#include <stdio.h>
//#include "pw4_ex3.c"
//#include "pw4_ex4.c"
//#include "pw4_ex5.c"

#define ROWS 6
#define COLUMNS 7

void count_aligned_disc(char Board[ROWS][COLUMNS])
{
    int left_horizontal, right_horizontal, up_vertical, right_up_diagonal, left_down_diagonal, left_up_diagonal, right_down_diagonal;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            int row_number = -(i - 6);
            if (Board[i][j] != ' ')
            {
                if (Board[i][j] == Board[i][j-1] && Board[i][j-1] == Board[i][j-2])
                {
                    left_horizontal = 3;
                    printf("box (%d,%d) corresponds to an alignment of %d discs left horizontally.\n",j+1,row_number,left_horizontal);
                }
                else if (Board[i][j] == Board[i][j+1] && Board[i][j+1] == Board[i][j+2])
                {
                    right_horizontal = 3;
                    printf("box (%d,%d) corresponds to an alignment of %d discs right horizontally.\n",j+1,row_number,right_horizontal);
                }
                else if (Board[i][j] == Board[i-1][j] && Board[i-1][j] == Board[i-2][j])
                {
                    up_vertical = 3;
                    printf("box (%d,%d) corresponds to an alignment of %d discs up vertically.\n",j+1,row_number,up_vertical);
                }
                else if (Board[i][j] == Board[i-1][j+1] && Board[i-1][j+1] == Board[i-2][j+2])
                {
                    if (j == 5 || j == 6)
                    {
                        continue;
                    }
                    right_up_diagonal = 3;
                    printf("box (%d,%d) corresponds to an alignment of %d discs right up diagonally.\n",j+1,row_number,right_up_diagonal);
                }
                else if (Board[i][j] == Board[i+1][j-1] && Board[i+1][j-1] == Board[i+2][j-2])
                {
                    if (j == 0 || j == 1)
                    {
                        continue;
                    }
                    left_down_diagonal = 3;
                    printf("box (%d,%d) corresponds to an alignment of %d discs left down diagonally.\n",j+1,row_number,left_down_diagonal);
                }
                else if (Board[i][j] == Board[i-1][j-1] && Board[i-1][j-1] == Board[i-2][j-2])
                {
                    if (j == 0 || j == 1)
                    {
                        continue;
                    }
                    left_up_diagonal = 3;
                    printf("box (%d,%d) corresponds to an alignment of %d discs left up diagonally.\n",j+1,row_number,left_up_diagonal);
                }
                else if (Board[i][j] == Board[i+1][j+1] && Board[i+1][j+1] == Board[i+2][j+2])
                {
                    if (j == 5 || j == 6)
                    {
                        continue;
                    }
                    right_down_diagonal = 3;
                    printf("box (%d,%d) corresponds to an alignment of %d discs right down diagonally.\n",j+1,row_number,right_down_diagonal);
                }
                else if (Board[i][j] == Board[i][j-1])
                {
                    if (left_horizontal == 3)
                    {
                        continue;
                    }
                    left_horizontal = 2;
                    printf("box (%d,%d) corresponds to an alignment of %d discs left horizontally.\n",j+1,row_number,left_horizontal);
                }
                else if (Board[i][j] == Board[i][j+1])
                {
                    if (right_horizontal == 3)
                    {
                        continue;
                    }
                    right_horizontal = 2;
                    printf("box (%d,%d) corresponds to an alignment of %d discs right horizontally.\n",j+1,row_number,right_horizontal);
                }
                else if (Board[i][j] == Board[i-1][j])
                {
                    if (up_vertical == 3)
                    {
                        continue;
                    }
                    up_vertical = 2;
                    printf("box (%d,%d) corresponds to an alignment of %d discs up vertically.\n",j+1,row_number,up_vertical);
                }
                else if (Board[i][j] == Board[i+1][j-1])
                {
                    if (left_down_diagonal == 3)
                    {
                        continue;
                    }
                    left_down_diagonal = 2;
                    printf("box (%d,%d) corresponds to an alignment of %d discs left down diagonally.\n",j+1,row_number,left_down_diagonal);
                }
                else if (Board[i][j] == Board[i-1][j-1])
                {
                    if (left_up_diagonal == 3)
                    {
                        continue;
                    }
                    left_up_diagonal = 2;
                    printf("box (%d,%d) corresponds to an alignment of %d discs left up diagonally.\n",j+1,row_number,left_up_diagonal);
                }
                else if (Board[i][j] == Board[i-1][j+1])
                {
                    if (right_up_diagonal == 3)
                    {
                        continue;
                    }
                    right_up_diagonal = 2;
                    printf("box (%d,%d) corresponds to an alignment of %d discs right up diagonally.\n",j+1,row_number,right_up_diagonal);
                }
                else if (Board[i][j] == Board[i+1][j+1])
                {
                    if (right_down_diagonal == 3)
                    {
                        continue;
                    }
                    right_down_diagonal = 2;
                    printf("box (%d,%d) corresponds to an alignment of %d discs right down diagonally.\n",j+1,row_number,right_down_diagonal);
                }
            }
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
        printf("\n");
        count_aligned_disc(Board);
    }
}*/
