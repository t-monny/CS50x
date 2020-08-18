#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)

{   
    float dollars;
    int coins = 0;
    int cents;
    
    do
    {
        dollars = get_float("How much change are you owed (in dollars)?\n");
    }
    while (dollars < 0);
    
    cents = round(dollars * 100);
    
    for ( ; cents >= 25; cents = cents - 25)
    {
        coins++;
    }
     for ( ; cents >= 10; cents = cents - 10)
    {
        coins++;
    }
    for ( ; cents >= 5; cents = cents - 5)
    {
        coins++;
    }
    for ( ; cents >= 1; cents = cents - 1)
    {
        coins++;
    }
    
    printf("%i\n",coins);
}


// If statements don't end in ';'
// For loops don't require "" but do require ending the though with ';'
// In my for loops, the first statement of int 'coins' is omitted as the value has already been set as '=round(dollars * 100);' in line 17
// built by Tim in Macclesfield, on 19 June 2020