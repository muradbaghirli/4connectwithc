#include <stdio.h>
#include <stdlib.h>
#include "pw4_ex3.c"
#include "pw4_ex4.c"
#include "pw4_ex5.c"

#define ROWS 6
#define COLUMNS 7

void recommend(char Board[ROWS][COLUMNS], int column)
{
    column = 1 + rand() % 7;
    if (possible_play(Board,column) == 1)
    {
        printf("You should play the column %d\n",column);
    }
    else
    {
        do
        {
            column = 1 + rand() % 7;
        } while (possible_play(Board,column) == 0);
        printf("You should play the column %d\n",column);
    }   
}

int main(void)
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
    printf("Enter player1's disc: ");
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
        printf("\n");
        recommend(Board,column);
    }
}
