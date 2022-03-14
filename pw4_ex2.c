#include <stdio.h>

#define ROWS 6
#define COLUMNS 7
char list_element = ' ';

void clear(char Board[ROWS][COLUMNS])
{
    /*
    This function clears the Connect 4 Board.
    : returns: the empty Connect 4 Board.
    */

    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            Board[row][column] = list_element;
        }

    }
    printf("%s",Board);
}

/*int main(void)
{
    char Board[ROWS][COLUMNS] = {
                                {'*', 'o', '*', 'o', '*', 'o', '*'},
                                {'o', '*', 'o', '*', 'o', '*', 'o'},
                                {'*', 'o', '*', 'o', '*', 'o', '*'},
                                {'o', '*', 'o', '*', 'o', '*', 'o'},
                                {'*', 'o', '*', 'o', '*', 'o', '*'},
                                {'o', '*', 'o', '*', 'o', '*', 'o'}
                                };
    clear(Board);
}*/
