#include <stdio.h>
#include <cs50.h>

int getHeight(void);
void makeHalfPyramids(int height);

int main(void)
{
    int height = getHeight();
    
    makeHalfPyramids(height);
    
    return 0;
}

int getHeight(void)
{
    int height = -1;
    //Reprompts if negative or above 23
    while(height < 0 || height > 23)
    {
    printf("Height: ");
    height = get_int();
    }
    return height;
}

// Input of an int height, prints # blocks in half pyramids seperated by two spaces
void makeHalfPyramids(int height)
{
    // Prints height number of lines
    for(int i = 0; i < height; i++)
    {
        // Spaces, adjusted by i-1 to start the pyramid at one #
        for(int j = 0; j < height-i-1; j++)
        {
            printf(" ");
        }
        // Blocks of #, adjusted by i+1 to start the pyramid at one #
        for(int k = 0; k < i+1; k++)
        {
            printf("#");
        }
        // Middle two spaces
        printf("  ");
        // # ran again for symmetry
        for(int k = 0; k < i+1; k++)
        {
            printf("#");
        }
        // Starts new line at end of pyramid halves
        printf("\n");
    }
}