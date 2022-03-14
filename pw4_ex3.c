#include <stdio.h>

#define ROWS 6
#define COLUMNS 7

void print_board(char Board[ROWS][COLUMNS])
{
    /*
    This function prints Connect 4 Board.
    :returns: printed Connect 4 Board
    */
    int rows_left = 6;
    int rows_right = 6;

    printf("  1 2 3 4 5 6 7\n");
    for (int row = 0; row < ROWS; row++)
    {
        printf("%d ",rows_left);
        rows_left--;

        for (int column = 0; column < COLUMNS; column++)
        {
            printf("%c ",Board[row][column]);
        }

        printf("%d \n",rows_right);
        rows_right--;
    }
    printf("  1 2 3 4 5 6 7");
}

/*int main(void)
{
    char Board[ROWS][COLUMNS] = {
                                {' ', ' ', '*', 'o', '*', 'o', '*'},
                                {' ', ' ', 'o', '*', 'o', '*', 'o'},
                                {' ', ' ', '*', 'o', '*', 'o', '*'},
                                {' ', ' ', 'o', '*', 'o', '*', 'o'},
                                {' ', ' ', '*', 'o', '*', 'o', '*'},
                                {' ', ' ', 'o', '*', 'o', '*', 'o'}
                                };
    print_board(Board);
}*/
