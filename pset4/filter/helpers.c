#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /* 
    Grayscale takes the average of the three colour values and applies to all three. */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            uint8_t av = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = av;
            image[i][j].rgbtGreen = av;
            image[i][j].rgbtRed = av;
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
    
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
