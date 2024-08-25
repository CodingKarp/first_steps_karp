#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cash);
int calculate_dimes(int cash);
int calculate_nickels(int cash);
int calculate_pennies(int cash);

int main(void)
{
    int cash;
    // gets owed change in cents from the user
    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash < 0);

    int quarters = calculate_quarters(cash);
    cash = cash - (quarters * 25); // substracts the value from cents
    int dimes = calculate_dimes(cash);
    cash = cash - (dimes * 10); // substracts the value from cents
    int nickels = calculate_nickels(cash);
    cash = cash - (nickels * 5); // substracts the value from cents
    int pennies = calculate_pennies(cash);
    cash = cash - pennies; // substracts the value from cents

    printf("%i \n", quarters + dimes + nickels + pennies); // prints the final sum
}
// calculates how many pennies to give
int calculate_pennies(int cash)
{
    int pennies = 0;
    while (cash >= 1)
    {
        pennies++;
        cash = cash - 1;
    }
    return pennies;
}
// calculates how many nickels to give
int calculate_nickels(int cash)
{
    int nickels = 0;
    while (cash >= 5)
    {
        nickels++;
        cash = cash - 5;
    }
    return nickels;
}
// calculates how many dimes to give
int calculate_dimes(int cash)
{
    int dimes = 0;
    while (cash >= 10)
    {
        dimes++;
        cash = cash - 10;
    }
    return dimes;
}
// calculates how many quarters to give
int calculate_quarters(int cash)
{

    int quarters = 0;
    while (cash >= 25)
    {
        quarters++;
        cash = cash - 25;
    }
    return quarters;
}
