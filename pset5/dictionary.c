/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 * with Hash Function with unsorted linked list
 * 
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"





#define hash_size 1800


typedef struct node 
{
    char word [LENGTH +1];  
    struct node* next;      
}
node;

node* HashTable [hash_size];

int count = 0;                                  // counting number of word in dictionary

unsigned int hash_function (const char* key);

char dict_word [LENGTH+1];                      //using for fscanf

/**
 * Returns true if word is in dictionary else false.
 */

bool check(const char* word)
{
    node* crawler = NULL;                           //make sure crawler does not contain anything first
    
    unsigned int hash = hash_function (word);       //hashing word will give us the index of bucket where it should be
    
    if (HashTable [hash] == NULL)                   // Usual NULL condition
        return false;
    
    else
    {    
        crawler = HashTable[hash];                  //crawler point at where HashTable[hash]points
                                                    // no need to malloc as it is just a pointer
        while (crawler != NULL)               // while it is not the end of linked list
        {
            if (strcasecmp (word, crawler->word) == 0)  // if matched
            
                return true;   
                
            if (strcasecmp (word, crawler->word) !=0)  // if not matched 
                                                        
                crawler = crawler->next;                // crawler moves to the next node
        }
        return false;
    }
        
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    for (int hash = 0; hash < hash_size; hash ++)   // hash table all pointers to NULL
    {
        HashTable[hash] = NULL;
    }

    FILE* dict = fopen (dictionary, "r");       // open dictionary for read
    
    if (dict == NULL)                           // NULL condition
    {
       
        printf ("error in opening file/n");
        return false;
    }
    
    while (true)
    {
            
        if (fscanf(dict, "%s\n", dict_word)==1)
        {
            
            int hash = hash_function (dict_word);  // hash it to get the index number of array 
        
            node* new_node = malloc (sizeof (node));    // allocate memory for new_node
                           
            if (new_node == NULL)                       // NULL condition
            {
                printf ("out of heap memeory\n");
                return false;
            }
            
            strcpy (new_node->word, dict_word);     //copy dict_word onto new_node->word
            
            if (HashTable[hash] == NULL)          //no linked list has been made from this bucket    
            {
                HashTable[hash] = new_node;         // HashTable point at new_node
                new_node->next = NULL;              
            }
            
            else //(HashTable[hash] != NULL)         // if linked list has been made
            {
                new_node->next = HashTable[hash];   // new_node points at where HashTable [hash] points at
                HashTable[hash] = new_node;         // then HashTable now points at new_node
            }
            count ++;
        }
        
        else
            break;
    
        
    }  
    
    fclose (dict);
    return true;
}

// hash function from cs50 Doug Lloyd, thank you !!!!
unsigned int hash_function (const char* key) // this does works see testtest.c
{   
    int sum = 0;
    
    for (int j = 0; j< strlen (key) ; j++) // char pointe can be passed onto strlen function see size_t strlen (const char* s)
    {
    
        sum += tolower(key[j]);   // make it all lowercase for adding value// sum of all ascii value of each word
        
    }
    return sum % hash_size;   // to make it within hash_size
    
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
        return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < hash_size; i++)
    {
        int hash = i;
        
        node* cursor = HashTable [hash];
        
        if (cursor == NULL)
            return true ;
            
        while (cursor->next != NULL)
        {
            node* temp = cursor;
            cursor = cursor -> next;
            free (temp);
        }
        HashTable [i] = NULL;  
    }
    
    return true; 
}
