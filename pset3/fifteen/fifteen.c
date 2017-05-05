/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    //-----if not regect as return 1
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    //-----so you put 4 on argv[1]
    //-----if not it will regect as return 2
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    //-----somesort of pointer and open file
    //-----if not regect as return 3
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    //i is raw j is colom 
    //last 2 need swap if d*d-1 is odd number
    //number of tile (d) on each raw and column starting 1
    //can be --- board [i][j]=d*d - 1 - (ix(d-1))-j-i
    
    int AllTile = d*d;
    int n = 0;
    int x;
    int y;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            n = (n + 1);
            board [i][j]= AllTile - n;
            
            while (board [d-1][d-1])
            {
                x = i;
                y = j;
                
                
            }
        }
    }  
    if (AllTile%2 == 0)
    {    
        int temp = board [d-1][d-2];
        board [d-1][d-2]=board [d-1][d-3];
        board [d-1][d-3]=temp;
    }
    
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
   // TODO
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        
        {
            if (board [i][j] > 0)
                printf ("| %2d", board [i][j]);
            if (board [i][j] == 0)
                printf ("| __");
        }    
            
        printf ("|\n");
    }

}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO

    // get x and y to remember where blanktile is


    
    for (int x = 0; x < d; x++)
    {
        for (int y= 0; y < d; y++)
        {
            while (board [x] [y] == 0 )
            {    
                for (int i = 0; i < d; i++)
                {
                    for (int j = 0; j < d; j++)
                    {
                        if (board [i][j] == tile)
                        {
                            if(((i==x) && ((j+1==y) || (j-1==y))) || (((i-1==x) || (i+1==x)) && (j==y)))
                            {    
                                board [x][y]= tile;
                                board [i][j]= 0;

                                
                                return true;
                            } 
                            else
                                return false;
                        }
                        
                    } 
                }
            }
        }
    }
    return false;
}



    // TODO
    //-----swap function 
    //-----swap number is easy but how to justify where it locate


/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int n = 1;
    // TODO
    // ---- need make sure about blank space 
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board [i][j]==n)
            {
                n = (n+1);
                if (n == d*d && board [d-1][d-1] == 0)
                    return true;
            }
            else
                return false;
        }
    }
    return false;
}