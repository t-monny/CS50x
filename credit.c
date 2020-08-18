#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    long number = get_long("Enter card number: \n");
    
    // Step 1 is to seperate the cardnumber into it's individual digits:
    long a = number / 1000000000000000;
    long b = number / 100000000000000 % 10;
    long c = number / 10000000000000 % 10;
    long d = number / 1000000000000 % 10;
    long e = number / 100000000000 % 10;
    long f = number / 10000000000 % 10;
    long g = number / 1000000000 % 10;
    long h = number / 100000000 % 10;
    long i = number / 10000000 % 10;
    long j = number / 1000000 % 10;
    long k = number / 100000 % 10;
    long l = number / 10000 % 10;
    long m = number / 1000 % 10;
    long n = number / 100 % 10;
    long o = number / 10 % 10;
    long p = number % 10;

    // Step 2 is to multiply every other digit by 2, starting with the second to last number ('o' in my case):
    int o2 = o * 2;
    int m2 = m * 2;
    int k2 = k * 2;
    int i2 = i * 2;
    int g2 = g * 2;
    int e2 = e * 2;
    int c2 = c * 2;
    int a2 = a * 2;
    
    //Step 3 is to add together the digits of the resulting products:
    int o_add = (o2 % 10) + (o2 / 10);
    int m_add = (m2 % 10) + (m2 / 10);
    int k_add = (k2 % 10) + (k2 / 10);
    int i_add = (i2 % 10) + (i2 / 10);
    int g_add = (g2 % 10) + (g2 / 10);
    int e_add = (e2 % 10) + (e2 / 10);
    int c_add = (c2 % 10) + (c2 / 10);
    int a_add = (a2 % 10) + (a2 / 10);

    int sum1 = (o_add + m_add + k_add + i_add + g_add + e_add + c_add + a_add);

    // Step 3 Add this sum to the sum of the remaining digits that weren't multiplied by 2:
    int sum2 = (b + d + f + h + j + l + n + p);
    int luhntotal = sum1 + sum2;
    
    // Step 4 Check the last digit of total is 0:
    int luhnlastdigit = luhntotal % 10;
    if (luhnlastdigit > 0)
    {
        printf("INVALID\n");
    }

    // Code using IF ELSE trees to print statements depending on whether both Luhn's algorithm is satisfied and...
    // ... individual card requirements are satisfied.
    if (luhnlastdigit == 0)
    {
        int AMEX = number / 1e13; 
        int MASTER = number / 1e14;
        int VISA13 = number / 1e12;
        int VISA16 = number / 1e15;
    
        // AMEX use 15-digit numbers AND start with either 34 or 37:
        if (AMEX == 34 || AMEX == 37)
        {
            printf("AMEX\n");
        }

        // MASTERCARD uses 16-digit numbers AND start with either 51,52,53,54 OR 55:
        else if (MASTER == 51 || MASTER == 52 || MASTER == 53 || MASTER == 54 || MASTER == 55)
        {
            printf("MASTERCARD\n");   
        }
        
        // VISA uses 13-digit AND 16-digit numbers, AND starts with 4
        else if (VISA13 == 4 || VISA16 == 4)
        {
            printf("VISA\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
    }
}

// Built by Tim in Macclesfield, June 22 2020
// Q: Why can't I use (number / 1e6) % 10; I have to instead use number / 1,000,000 % 10