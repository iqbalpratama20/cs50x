#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Initialize height variable
    int height;

    // Will not take value smaller than 1 or larger than 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Build right aligned triangle based on input height
    for (int i = 0; i < height; i++)
    {
        // Generate white spaces
        for (int j = height; j > i + 1; j--)
        {
            printf(" ");
        }

        // Generate hashtag
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Create new line so the hash will not be in one line
        printf("\n");
    }
}
