//how many coins need for change

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change_input;
    int coin_count = 0;

    printf("How much change is owed?:\n");

    do
    {
        change_input = GetFloat();
        
        if (change_input <= 0)
        {
            printf ("Boo it must be a positive number. How much change is owed?\n");
        }

    }
    while (change_input <= 0);

    int change_remind = roundf ((change_input * 100));

    while (change_remind >= 25)
    {
        change_remind -= 25;
        coin_count++;
    }
    
    while (change_remind >= 10)
    {
        change_remind -= 10;
        coin_count++;
    }

    while (change_remind >= 5)
    {
        change_remind -= 5;
        coin_count++;
    }
    while (change_remind >= 1)
    {
        change_remind -= 1;
        coin_count++;
    }

    printf ("%d\n" , coin_count);

}