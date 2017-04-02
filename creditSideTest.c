#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    bool countFlag = 0;
    int i = 0;
    
    while(countFlag == 0)
    {
        if((cardNumber / (long long)pow(10,i)) == 0)
        {
        countFlag = 1;
        }
        i++;
    }
    
    int digits = i-1;
    
    printf("digits %i\n", digits);
    
    int numArray[digits];
    
    for(i = 0; i < digits; i++)
    {
        numArray[(digits-1)-i] = cardNumber % 10;
        cardNumber = cardNumber / 10;
    }
    
    for(i = 0; i < digits; i++)
    {
        printf("%i", numArray[i]);
    }
    
    int prodSum = 0;
    printf("\n");
    
    for(i = (digits-2); i >= 0; i-=2)
    {
        printf("%i", numArray[i]);
        if(numArray[i] < 5)
        {
            prodSum += numArray[i]*2;
        }
        else
        {
            prodSum += (1 + (numArray[i]-5)*2);
        }
    }
    
    printf("prodSum: %i\n", prodSum);
    int totSum = prodSum;
    
    for(i = (digits-1); i >= 0; i-=2)
    {
        totSum += numArray[i];
    }
    
    if(totSum%10 == 0)
    {
        if(numArray[0] == 4 && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
        }
        if(numArray[0] == 3 && digits == 15)
        {
            if(numArray[1] == 4 || numArray[1] == 7)
            {
                printf("AMEX\n");
            }
        }
        if(numArray[0] == 5 && digits == 16)
        {
            if(numArray[1] > 0 && numArray[1] < 6)
            {
                printf("MASTERCARD\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}
