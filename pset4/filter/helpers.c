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
            int blue = 0;
            int green = 0;
            int red = 0;

            // Create a variable to count how many boxes are valid (from 4 to 9). Default will be 9, and will minus as we remove boxes.
            uint8_t div = 9;

            for (x = i - 1; x <= i + 1; x++)
            {
                if (x < 0)
                {
                    // If entire row is not present, then remove 3 divisors.
                    div = div - 3;
                }
                else
                {
                    for (y = j - 1; y <= j + 1; y++)
                    {
                        if (y < 0)
                        {
                            // If a column is not present, then remove 1 divisor.
                            div = div - 1;
                        }
                        else
                        {
                            // Add in RGB data for later calculation.
                            blue = blue + image[x][y].rgbtBlue;
                            green = green + image[x][y].rgbtGreen;
                            red = red + image[x][y].rgbtRed;
                        }                        
                    }
                }
            }
            // Now to calculate and put in the new value into the temp array.
            temp[i][j].rgbtBlue = blue / div;
            temp[i][j].rgbtGreen = green / div;
            temp[i][j].rgbtRed = red / div;
        }
    }
    // Copy temp data back into original array.
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[i][j] = temp[i][j];
        }
    }    
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
