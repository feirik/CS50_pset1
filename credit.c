#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long getCardNumber(void);
int countDigits(long long cardNumber);
void verifyCardCompany(long long cardNumber, int digits);

int main(void)
{
    long long cardNumber = getCardNumber();
    int digits = countDigits(cardNumber);
    
    // Checking digits in main for efficiency, rechecked in function
    if(digits == 13 || digits == 15 || digits == 16)
    {
        verifyCardCompany(cardNumber, digits);
    }
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}

long long getCardNumber(void)
{
    printf("Number: ");
    long long cardNumber = get_long_long();
    return cardNumber;
}

int countDigits(long long cardNumber)
{
    int digits = 0;
    
    // Dividing cardNumber by 10^digits until the result is zero
    while((cardNumber / (long long)pow(10,digits)) != 0)
    {
        digits++;
    }
    
    return digits;
}

void verifyCardCompany(long long cardNumber, int digits)
{
    int numArray[digits];
    
    for(int i = 0; i < digits; i++)
    {
        // Placing the remainder at the rightmost slot in array
        numArray[(digits-1)-i] = cardNumber % 10;
        // Removing the already stored digit from cardNumber
        cardNumber = cardNumber / 10;
    }
    
    int luhnSum = 0;
    
    // Second-to-last digits sums
    for(int i = (digits-2); i >= 0; i-=2)
    {
        // If 4 or less, double and add to sum
        if(numArray[i] < 5)
        {
            luhnSum += numArray[i]*2;
        }
        // If 5 or more, sum of digits is 1 + (initial digit - 5)*2
        else
        {
            luhnSum += (1 + (numArray[i]-5)*2);
        }
    }
    
    // Rest of the digit sums
    for(int i = (digits-1); i >= 0; i-=2)
    {
        luhnSum += numArray[i];
    }
    
    if(luhnSum%10 == 0)
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
}