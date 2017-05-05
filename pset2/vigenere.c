// vigenere encipher by ichi

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    
    if (argc != 2)
    {   
        printf ("please input a key wordon second command line\n");
        return 1;
    }
    
    // inputs k (string) should be on argn[1]
    string k =  argv[1];
    
    //check if inputs are alpha
    for (int y = 0, klengh = strlen(argv[1]); y < klengh; y++)
    {
        if (!isalpha (k[y]))
        {
            printf ("not a prompt for input\n");
            return 1;
        }
    }    
    
    // get user imput of plainetext
    string p = GetString();
    
    // define & while loop
    int i = 0;
    int x = 0;
    int n = strlen (p);
    int c; 
    
    while ( i < n )
    {

        if (!isalpha (p[i]))
        {    
            printf ("%c", p[i]);
            i++;
        }         
        
        else if (isalpha (p[i]))
        {
            //find out which array (j) of keyword (k) will be used for p[i] 
            //using x which is number of array for only alphabet 
            int j = x % strlen(k);
        
            // k[j]-'A' is number of shift
            // c is ascii number of shifted alphabet
            if isupper (k[j])
                c = p[i] + k[j]-'A';
        
            if islower (k[j])
                c = p[i] + k[j]-'a';
            
            if ((isupper (p[i]) && c > 'Z') || (islower (p[i]) && c > 'z'))
                c = c - 26;
            
            printf ("%c",c);
            x++;
            i++;
        
        }
    }
    
    printf ("\n");
    return 0;
}