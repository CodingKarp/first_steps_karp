#include <cs50.h>
#include <stdio.h>

void print_row(int length);
void space(int spaces);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1); // get's the amount of rows from the user (only more than 1)

    for (int i = 0; i < height; i++)
    {
        space(height - (i + 1)); // in order to get optimal amount of space in every next raw to
                                 // make the piramid right alighned
        print_row(i + 1);
    }
}

void print_row(int bricks) // varaiable for printing '#'
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#"); // prints '#'
    }
    printf("\n"); // after it printed needed amount of '#' goes to the next raw
}

void space(int spaces) // varaiable for printing 'spaces'
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}
