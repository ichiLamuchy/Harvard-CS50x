// make a mario pyramid

#include <stdio.h>
#include <cs50.h>
 
int main(void)
{

int height;

    do
    {
        printf("height:");
        height = GetInt();
    }

    while (( height < 0 ) || ( height > 23 ));

//loop for each row

    for (int rows = 1; rows <= height; rows++) 
    {

        for (int space = (height - rows); space > 0; space--)
        {
            printf(' '); 
        }
 
        for (int hash = 1; hash <= (rows + 1); hash++)
        {   
            printf('#'); 
        }
 
        printf("\n");
    }
    return 0;
    
}