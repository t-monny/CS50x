#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    for (int row = 1; row <= height; row++)
    {
        // Print an amount of spaces to correctly justify the left side of pyramid, amount of space decreases with each row. 
        for (int space = height; space > row; space = space - 1)
        {
            printf(" ");
        }
        
        // Print an amount of # symbol, increasing with each row:
        for (int L = 1; L <= row; L++)
        {
            printf("#");
        }
        
        // Print double space to make inside of pyramid
        printf("  ");
        
        // Print an amount of # symbol, increasing with each row. No spaces needed afterwards:
        for (int R = 1; R <= row; R++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// note to self: revisit 'for' loops, they don't use " " or end in ';'
// OR keyword '||' was my friend!
// using operators based on variable 'row' in the for loops allowed me to...
//...link amount of characters printed to the row number currently printing on.
// Built by Tim in Macclesfield, 19 June 2020