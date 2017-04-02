#include <stdio.h>
#include <cs50.h>

int getShowerTime(void);
void calculateBottles(int minutes);

int main(void)
{
    int minutes = getShowerTime();
    calculateBottles(minutes);
    return 0;
}

int getShowerTime(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    return minutes;
}

void calculateBottles(int minutes)
{
    printf("Bottles: %i\n", minutes*12);
}