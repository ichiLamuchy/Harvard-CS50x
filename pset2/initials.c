// Get intiials of input name

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    //get name input 
    string s = GetString();
    
    //loop for each letter on the name
    for (int i = 0, n = strlen(s); i < n; i++)  
    {
        if ( i == 0 ) //the first letter
    
        printf ("%c", toupper(s[i]));
    
        else if (s[i] == ' ') //the letter right after ' '
        
        printf ("%c", toupper(s[i+1]));
     }
 

 printf ("\n");

 }
