#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            float average = round((image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / (float)3);
            image[row][col].rgbtRed = average;
            image[row][col].rgbtGreen = average;
            image[row][col].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int originalRed = image[row][col].rgbtRed;
            int originalGreen = image[row][col].rgbtGreen;
            int originalBlue = image[row][col].rgbtBlue;

            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            image[row][col].rgbtRed = sepiaRed > 255 ? 255 : round(sepiaRed);
            image[row][col].rgbtBlue = sepiaBlue > 255 ? 255 : round(sepiaBlue);
            image[row][col].rgbtGreen = sepiaGreen > 255 ? 255 : round(sepiaGreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width / 2; col++)
        {
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - 1 - col];
            image[row][width - 1 - col] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copiedImage[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            copiedImage[row][col] = image[row][col];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int red_total = 0, green_total = 0, blue_total = 0;
            int total = 0;

            for (int x = -1; x <= 1; x++)
            {
                int row_index = row - x;
                if (row_index < 0 || row_index > height)
                {
                    continue;
                }

                for (int y = -1; y <= 1; y++)
                {
                    int col_index = col - y;

                    if (col_index < 0 || col_index > width)
                    {
                        continue;
                    }

                    red_total += copiedImage[row_index][col_index].rgbtRed;
                    green_total += copiedImage[row_index][col_index].rgbtGreen;
                    blue_total += copiedImage[row_index][col_index].rgbtBlue;
                    total++;
                }
            }

            image[row][col].rgbtRed = red_total / total;
            image[row][col].rgbtGreen = green_total / total;
            image[row][col].rgbtBlue = blue_total / total;
        }
    }
    return;
}