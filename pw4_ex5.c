#include <stdio.h>
//#include "pw4_ex4.c"

#define ROWS 6
#define COLUMNS 7

void drop_disc(char Board[ROWS][COLUMNS], int column, char disc)
{
    /* This function  puts the player's disc into the grid.
    :param col: vertical lines of the grid
    :type col: int
    :param player: player's disc
    :type player: str
    :returns: Board with the disc of the list player
    */
    for (int row = ROWS-1; row > -1; row--)
    {
        if (possible_play(Board,column))
        {
            if (Board[row][column-1] == ' ')
            {
                Board[row][column-1] = disc;
                break;
            }
        }

        else
        {
            printf("Column %d has filled. Please enter another number.",column);
            printf("Enter the column between [1-7] where you want to mark : ");
            scanf("%d",&column);
            printf("\n");
            drop_disc(Board,column,disc);
            break;
        }
    }
    
}

/*int main(void)
{
    char Board[ROWS][COLUMNS] = {
                                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' '}
                                };
    int column;
    char disc;
    printf("Enter the first player's disc: ");
    scanf("%c",&disc);  
    while (1)
    {                 
        printf("\nEnter the column between [1-7] where you want to mark: ");
        scanf("%d",&column);
        while (1)
        {
            if(column<1 || column>7)
            {
                printf("Column %d doesn't exist.Enter another column between [1-7] where you want to mark: ",column);
                scanf("%d",&column);
            }
            else
            {
                break;
            }
        }
        if (disc == '*')
        {
            drop_disc(Board,column,disc);
            disc = 'o';
        }
        else
        {
            drop_disc(Board,column,disc);
            disc = '*';
        }
        print_board(Board);
    }
}*/
