/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // n is number of imput (starting from 0)
    // n is size
    int j,i;
    
    if (n < 1)
    {
        if (value == values[0])
        return true;
        
        else
        return false;
    }    
    i = 0;
    while (n > 0)
    {
        if (values[i] == values[n])
        {    
            if (value == values[i])
                return true;
                
            else
                return false;
        }        
        else 
        {
            j = (i + n)/2;
            
            if (value == values[j] )
                return true;
        
            if (value > values[j])
                i = j+1;
            
            if (value < values[j])
                n = j-1;
        }
    }
    return false;
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    //int n is times of impliment
    //bubble sort
    int i,j,temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i; j++) //j is each
        {
            if (values[j] > values[j+1])
            {
                temp = values[j+1];
                values[j+1] = values[j];
                values[j] = temp;
            }
        }        
    }
    n=j;

    return;
}