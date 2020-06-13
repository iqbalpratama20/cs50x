#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Variables initialization for coins available
    int QUARTERS = 25;
    int DIMES = 10;
    int NICKELS = 5;
    int PENNIES = 1;

    float dollars;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // Cast dollars input into cents by rounding it
    int cents = round(dollars * 100);
    int count = 0;

    while (cents > 0)
    {
        // Substract a quarter if change is still larger than or equal 25c
        if (cents >= QUARTERS)
        {
            cents = cents - QUARTERS;
            count++;
        }

        // Substract a dime if change is still larger than or equal 10c
        else if (cents >= DIMES)
        {
            cents = cents - DIMES;
            count++;
        }

        // Substract a nickel if change is still larger than or equal 5c
        else if (cents >= NICKELS)
        {
            cents = cents - NICKELS;
            count++;
        }

        // Substract a penny if change is still larger than or equal 1c
        else
        {
            cents = cents - PENNIES;
            count++;
        }
    }

    // Print minimum number of coins needed for change
    printf("%i\n", count);
}
