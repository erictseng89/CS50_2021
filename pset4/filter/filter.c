#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char *argv[])
{

    /* 
    Define allowable filters
    This is a char array that will tell the program which command-line arguments are allowed. b: blue, e: edge detection, g: grayscale, r: reflection. */
    char *filters = "begr";

    /* 
    Get filter flag and check validity
    int getopt() (get option) is a function that parses the command-line arguments and if the user had used the program correctly, getopt will returns the optional character (which in this case is one of "begr"). 
    You need to pass getopt argc, argv and a string(called the optstring), where each character of the string is a option (the char *filters is used here). */
    /* 
    getopt will return the an option into the var.char "filter" */
    char filter = getopt(argc, argv, filters);
    /* 
    If ? is returned, it means that the user inputted an option that was not in the optstring. */
    if (filter == '?')
    {
        fprintf(stderr, "Invalid filter.\n");
        return 1;
    }

    /* 
    Ensure only one filter
    int getopt (), if this function returns -1, it indicates that there are no options to be found. */
    if (getopt(argc, argv, filters) != -1)
    {
        fprintf(stderr, "Only one filter allowed.\n");
        /* 
        extern FILE *stderr is an external file stream that is initialized whenever a UNIX program starts. I'm not sure how to access stderr. */
        return 2;
    }

    /*
    Ensure proper usage
    At this point in the program, it has been identified that the user has correctly inputed 1 and only 1 option. Now to check that the remaining arguments are correct.
    extern int optind (option indicator) is just a int variable which helps getopt() keep track of the command-line arguments. int optind initializes at index 1, which is where the first command line element will be (index 0 is the program name itself). 
    Once getopt() has successfully returned an option, optind will increase. If there are no more options in the remaining elements, optind will equal the index of the first non option element.
    In this program: program start, optind == 1; getopt() returned an option, optind == 2; getopt() returned -1 (indicating no more options), optind == 2 (optind will remain at 2)
    So this if operative is informing the user that the option element must be right after the program name, and that there should only be 4 total elements in the command-line (program name + 3 elements). */
    if (argc != optind + 2)
    {
        fprintf(stderr, "Usage: filter [flag] infile outfile\n");
        return 3;
    }

    // Remember filenames
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 4;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 6;
    }

    // int abs(int j) returns the absolute value of int j, which in this case is the value of bi.biHeight.
    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    /*
    Allocate memory for image
    calloc() function allocates an array of nmemb(number of elements) of indicated size, and returns a pointer.
    Here, we are trying to create memory to store the pixel data.*/
    RGBTRIPLE (*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        fprintf(stderr, "Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    /* 
    Determine padding for scanlines
    The pixel data of bmp files must be a multiple of 4 in each row. int padding is used to determine how much padding will be needed when we transform the image. */
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
        // Read row into pixel array
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        // Skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    // Filter image
    switch (filter)
    {
        // Blur
        case 'b':
            blur(height, width, image);
            break;

        // Edges
        case 'e':
            edges(height, width, image);
            break;

        // Grayscale
        case 'g':
            grayscale(height, width, image);
            break;

        // Reflect
        case 'r':
            reflect(height, width, image);
            break;
    }

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Write new pixels to outfile
    for (int i = 0; i < height; i++)
    {
        // Write row to outfile
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // Write padding at end of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Free memory for image
    free(image);

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    return 0;
}
