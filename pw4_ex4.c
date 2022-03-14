#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLUMNS 7

bool possible_play(char Board[ROWS][COLUMNS], int position)
{
    /*
    This function shows if the player can put his disk on the chosen place.
    : param position: the chosen place to put the disk
    : type position: int 
    : returns: True if the player can put his disk there or False if not
    */
    if (Board[0][position-1] == ' ' && position >= 1 && position <= 7 )
    {
        // valid move
        return true;
    }
    else
    {
        // invalid move 
        return false;
    }
}

/*int main(void)
{
    char Board[ROWS][COLUMNS] = {
                                {'o', ' ', ' ', ' ', ' ', ' ', 'o'},
                                {'*', ' ', ' ', ' ', ' ', ' ', '*'},
                                {'o', ' ', ' ', ' ', ' ', ' ', 'o'},
                                {'*', ' ', ' ', ' ', ' ', ' ', '*'},
                                {'o', ' ', ' ', ' ', ' ', ' ', 'o'},
                                {'*', ' ', ' ', ' ', ' ', ' ', '*'}
                                };
    printf("%d",possible_play(Board,7));
}*/
