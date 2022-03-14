#include <stdio.h>
#include <stdbool.h>
#include "game_win.c"
#include "pw4_ex3.c"
#include "pw4_ex4.c"
#include "pw4_ex5.c"
#include "pw4_ex6.c"

#define ROWS 6
#define COLUMNS 7

void improve_advice(char Board[ROWS][COLUMNS], char disc)
{
    int left_horizontal, right_horizontal, up_vertical, right_up_diagonal, left_down_diagonal, left_up_diagonal, right_down_diagonal;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (Board[i][j] == disc)
            {
                if (Board[i][j] == Board[i][j-1] && Board[i][j-1] == Board[i][j-2])
                {
                    if (j <= 2)
                    {
                        left_horizontal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j-2);
                    }
                }
                else if (Board[i][j] == Board[i][j-1])
                {
                    left_horizontal = 2;
                    printf("Player %c should play the column %d\n",disc,j-1);
                }
                if (Board[i][j] == Board[i][j+1] && Board[i][j+1] == Board[i][j+2])
                {
                    if (j >= 4)
                    {
                        continue;
                    }
                    else
                    {
                        right_horizontal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j+4);
                    }
                    break;
                }
                else if (Board[i][j] == Board[i][j+1])
                {
                    if (j >= 5)
                    {
                        continue;
                    }
                    else
                    {
                        right_horizontal = 2;
                        printf("Player %c should play the column %d\n",disc,j+3);
                    }
                }
                if (Board[i][j] == Board[i-1][j] && Board[i-1][j] == Board[i-2][j])
                {
                    up_vertical = 3;
                    printf("Player %c should play the column %d to win\n",disc,j+1);
                    break;
                }
                else if (Board[i][j] == Board[i-1][j])
                {
                    up_vertical = 2;
                    printf("Player %c should play the column %d\n",disc,j+1);
                    printf("Hello World");
                    break;
                }
                if (Board[i][j] == Board[i-1][j+1] && Board[i-1][j+1] == Board[i-2][j+2])
                {
                    if (j >= 4)
                    {
                        continue;
                    }
                    else
                    {
                        right_up_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j+4);
                    }
                    break;
                }
                else if (Board[i][j] == Board[i-1][j+1])
                {
                    if (j >= 5)
                    {
                        continue;
                    }
                    else
                    {
                        right_up_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j+3);
                    }
                }
                if (Board[i][j] == Board[i+1][j-1] && Board[i+1][j-1] == Board[i+2][j-2])
                {
                    if (j <= 2)
                    {
                        continue;
                    }
                    else
                    {
                        left_down_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j-2);
                    }
                    break;
                }
                else if (Board[i][j] == Board[i+1][j-1])
                {
                    if (j <= 1)
                    {
                        continue;
                    }
                    else
                    {
                        left_down_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j-1);
                    }
                }
                if (Board[i][j] == Board[i-1][j-1] && Board[i-1][j-1] == Board[i-2][j-2])
                {
                    if (j <= 2)
                    {
                        continue;
                    }
                    else
                    {
                        left_up_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j-2);
                    }
                    break;
                }
                else if (Board[i][j] == Board[i-1][j-1])
                {
                    if (j <= 1)
                    {
                        continue;
                    }
                    else
                    {
                        left_up_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j-1);
                    }
                }
                if (Board[i][j] == Board[i+1][j+1] && Board[i+1][j+1] == Board[i+2][j+2])
                {
                    if (j >= 4)
                    {
                        continue;
                    }
                    else
                    {
                        right_down_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j+4);
                    }
                    break;
                }
                else if (Board[i][j] == Board[i+1][j+1])
                {
                    if (j >= 5)
                    {
                        continue;
                    }
                    else
                    {
                        right_down_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j+3);
                    }
                }
            }
        }
    }

}

int main(void)
{
    int column;
    char disc;
    printf("Enter the first player's disc: ");
    scanf("%c",&disc);  
    while (!Win())
    {                 
        printf("\nPlayer '%c' enter the column between [1-7] where you want to mark: ",disc);
        scanf("%d",&column);
        while (1)
        {
            if(column<1 || column>7)
            {
                printf("Column %d doesn't exist. Player '%c' enter another column between [1-7] where you want to mark: ",column,disc);
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
        //count_aligned_disc(Board);
        improve_advice(Board,disc);
    }
}
