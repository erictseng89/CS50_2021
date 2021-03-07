#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    Grayscale takes the average of the three colour values and applies to all three. */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float av_t = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            uint8_t av = round(av_t);
            image[i][j].rgbtRed = av;
            image[i][j].rgbtGreen = av;
            image[i][j].rgbtBlue = av;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    Create an RGBTRIPLE array of size width.
    Copy each width before rewriting them back in the opposite order. */
    RGBTRIPLE temp[width];
    for (int i = 0; i < height; i++)
    {
        for (int x = 0; x < width; x++)
        {
            if (width < 1)
            {
                return;
            }
            temp[width - x - 1] = image[i][x];
        }
        for (int j = 0 ; j < width; j++)
        {
            image[i][j] = temp[j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    Look at the the location where current height - 1, current width - 1, and use that as the starting point.
    Create another temp array to store the information. The temp array will be of [height][width] and will store the blur information.
    Once we have successfully populated the temp array, then we can copy back original array.  */

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create two int values to record the starting location (the top left grid of the 3x3 blur box).
            int x, y;

            // Create temp variables (must be int as the values may exceed the size of a byte) to use to calculate the values.
            int Red = 0;
            int Green = 0;
            int Blue = 0;

            // Create a variable to count how many boxes are valid (from 4 to 9). Default will be 9, and will minus as we remove boxes.
            float div = 9.0;

            for (x = i - 1; x <= i + 1; x++)
            {
                if (x < 0 || x >= height)
                {
                    // If entire row is not present, then remove 3 divisors.
                    div = div - 3;
                }
                else
                {
                    for (y = j - 1; y <= j + 1; y++)
                    {
                        if (y < 0 || y >= width)
                        {
                            // If a column is not present, then remove 1 divisor.
                            div = div - 1;
                        }
                        else
                        {
                            // Add in RGB data for later calculation.
                            Red = Red + image[x][y].rgbtRed;
                            Green = Green + image[x][y].rgbtGreen;
                            Blue = Blue + image[x][y].rgbtBlue;
                        }
                    }
                }
            }
            // Now to calculate and put in the new value into the temp array.

            float Red_t = Red / div;
            float Green_t = Green / div;
            float Blue_t = Blue / div;

            temp[i][j].rgbtRed = round(Red_t);
            temp[i][j].rgbtGreen = round(Green_t);
            temp[i][j].rgbtBlue = round(Blue_t);
        }
    }
    // Copy temp data back into original array.
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[a][b] = temp[a][b];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    Sobel operator will use a method similar to the blur function. We will use the 3x3 box of pixels surrounding the target pixel and calculate a value.
    The calculation will be done twice, once for the Gx value, and once for Gy. I will represent Gx and Gy in an array.
    The perimeter of the bmp image we will assign a value of 0 for all 3 colours.

    We need to create an array to store the new values to.
    We will also need a temp variable to store the int numbers, as RGBTRIPLE only allows up to 255.
    */

    // Sobel Operator Matrix
    int gm[2][3][3] = {{{-1, 0, -1}, {-2, 0, 2}, {-1, 0, 1}}, {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}};

    /* for (int s = 0; s < 2; s++)
    {
        for (int t = 0; t < 3; t++)
        {
            for (int u = 0; u < 3; u++)
            {
                printf("%i ", gm[s][t][u]);
            }
            printf("\n");
        }
        printf("\n");
    } */

    // 0 Value for edges indicating black.
    uint8_t edge = 0;

    // Temporary arrays to store the calculated values for each pixel.
    RGBTRIPLE temp[2][height][width];


    // Temporary variables to store calculations, need 3 for each color. Will reset to 0 after each calculation.

    // Will use an array, 0 = Red, 1 = Green, 2 = Blue.
    int calc[3] = {0, 0, 0};

    // Loop for Gx and Gy.
    for (int g = 0; g < 2; g++)
    {
        // DEBUG
/*         if (g == 1)
        {
            printf("Debug.\n");
        } */
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // DEBUG
                if (j == 599)
                {
                    ;
                }
                
                // Reinitialize calc
                for (int reset_calc = 0; reset_calc < 3; reset_calc++)
                {
                    calc[reset_calc] = 0;
                }

                float div = 1.0;


                // Create two int values to record the starting location (the top left grid of the 3x3 blur box).
                int x = 0;
                int y = 0;

                // Use 2 int variables for tracking current 3x3 grid.
                int mx = 0;
                int my = 0;

                // Now that we have identified the 3x3 box, we need to calculate.
                for (x = i - 1; x <= i + 1; x++)
                {
                    for (y = j - 1; y <= j + 1; y++)
                    {

                        // If current pixel is edge.
                        if (x < 0 || x >= height || y < 0 || y >= width)
                        {
                            for (int c = 0; c < 3; c++)
                            {
                                calc[c] = calc[c] + edge;
                            }
                            my++;
                        }
                        // Multiply values with matrix.
                        else
                        {
                            // For debugging purposes.
                            int check_rgb[3] = {image[x][y].rgbtRed, image[x][y].rgbtGreen, image[x][y].rgbtBlue};
                            calc[0] = calc[0] + gm[g][mx][my] * check_rgb[0];
                            calc[1] = calc[1] + gm[g][mx][my] * check_rgb[1];
                            calc[2] = calc[2] + gm[g][mx][my] * check_rgb[2];

                            /* calc[0] = calc[0] + gm[g][mx][my] * image[x][y].rgbtRed;
                            calc[1] = calc[1] + gm[g][mx][my] * image[x][y].rgbtGreen;
                            calc[2] = calc[2] + gm[g][mx][my] * image[x][y].rgbtBlue; */
                            my++;
                        }
                    }
                    mx++;
                    my = 0;
                }

                // Divide by divisor, then store to temp array.
                for (int k = 0; k < 3; k++)
                {
                    float calc_t = calc[k] * div;
                    calc[k] = round(calc_t);
                    if (calc[k] >= 255)
                    {
                        calc[k] = 255;
                    }
                    else if (calc[k] < 0)
                    {
                        calc[k] = 0;
                    }
                    
                }

                // Place values into temp RGBTRIPLE array.
                temp[g][i][j].rgbtRed = calc[0];
                temp[g][i][j].rgbtGreen = calc[1];
                temp[g][i][j].rgbtBlue = calc[2];
            }
        }
    }

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            // Create floats to later use for rounding.
            float temp_rgb[3];
            temp_rgb[0] = sqrt(pow(temp[0][a][b].rgbtRed, 2) + pow(temp[1][a][b].rgbtRed, 2));
            temp_rgb[1] = sqrt(pow(temp[0][a][b].rgbtGreen, 2) + pow(temp[1][a][b].rgbtGreen, 2));
            temp_rgb[2] = sqrt(pow(temp[0][a][b].rgbtBlue, 2) + pow(temp[1][a][b].rgbtBlue, 2));

            image[a][b].rgbtRed = round(temp_rgb[0]);
            image[a][b].rgbtGreen = round(temp_rgb[1]);
            image[a][b].rgbtBlue = round(temp_rgb[2]);
        }
    }

    return;
}
