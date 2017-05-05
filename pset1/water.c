// how many bottle of water are required for shower

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    printf ("minutes: ");
    int n = GetInt();
    
    if (n <= 0)
        printf ("Please put positive number");
        
    else
        printf ("bottels: %d\n", n*12);
    
}

   


