#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

//Group: Ismayil Abdullazada, Nihat Babayev, Murad Baghirli, Nijat Zeynalli

#define ROWS 6
#define COLUMNS 7
char list_element = ' ';

// "*" represents the red discs
// "o" = represents the yellow discs


// The Connect 4 Board written by Nijat Zeynalli
char Board[ROWS][COLUMNS] = {
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '}
                            };




//Board cleaning function written by Nihat Babayev
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


//Validity function written by Murad Baghirli
bool possible_play(char Board[ROWS][COLUMNS], int position)
{
    /*
    This function checks whether the the column player entered is valid or not.
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


//Written by Ismayil Abdullazada
void drop_disc(char Board[ROWS][COLUMNS], int column, char disc)
{
    /* This function drops the player's disc into the grid.
    :param column: vertical lines of the grid
    :type column: int
    :param disc: player's disc
    :type disc: char
    :returns: Board with the disc of the list player in it
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



//Written by Nihat Babayev
bool horizWin(char Board[ROWS][COLUMNS])
{
    /*
    Checks if the player has 4 same disks in one horizontal line."""
    :returns: True or False
    */

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (Board[row][col] != ' ')
            {
                if (Board[row][col] == Board[row][col+1] && Board[row][col] == Board[row][col+2] && Board[row][col] == Board[row][col+3])
                {
                   printf("\n");
                   printf("Player %c has won the game!",Board[row][col]);
                   printf("\n");
                   printf("Game Over!");
                   return true; 
                }
            }
        }
    }    
    return false;
}


//Written by Ismayil Abdullazada
bool vertWin(char Board[ROWS][COLUMNS])
{
    /*
    Checks if the player has 4 same disks in one vertical line.
    :returns: True or False
    */

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            if (Board[row][col] != ' ')
            {
                if (Board[row][col] == Board[row+1][col] && Board[row][col] == Board[row+2][col] && Board[row][col] == Board[row+3][col])
                {
                   printf("\n");
                   printf("Player %c has won!",Board[row][col]);
                   printf("\n");
                   printf("Game Over!");
                   return true;
                }
            }
        }
    }
    return false;
}


//Written by Ismayil Abdullazada, Murad Baghirli, Nijat Zeynalli, Nihat Babayev
bool diagWin(char Board[ROWS][COLUMNS])
{
    /*
    Checks  if the player has 4 same disks in one diagonal line.
    :returns: True or False
    */

    //check for starting position of diagonal
    //going up and to the right
    for (int row = 3; row < ROWS; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (Board[row][col] != ' ')
            {
                if (Board[row][col] == Board[row-1][col+1] && Board[row][col] == Board[row-2][col+2] && Board[row][col] == Board[row-3][col+3])
                {
                   printf("\n");
                   printf("Player %c has won!",Board[row][col]);
                   printf("\n");
                   printf("Game Over!");
                   return true;
                }
            }
        }
    }

    //check for starting position of diagonal
    //going down and to right
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (Board[row][col] != ' ')
            {
                if (Board[row][col] == Board[row+1][col+1] && Board[row][col] == Board[row+2][col+2] && Board[row][col] == Board[row+3][col+3])
                {
                    printf("\n");
                    printf("Player %c has won!",Board[row][col]);
                    printf("\n");
                    printf("Game Over!");
                    return true;
                }
            }
        }
    }
    return false;
}



//Written by Ismayil Abdullazada
bool Win()
{
    /*
    Checks if the player wins.
    :returns: True or False
    */

    if (horizWin(Board) || vertWin(Board) || diagWin(Board))
    {
        return true;
    }
    return false;
}


void recommend_column(char Board[ROWS][COLUMNS], int column)
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



//Written by Ismayil Abdullazada, Nihat Babayev
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
                    if (j <= 1)
                        continue;
                    left_horizontal = 3;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs left horizontally.\n",j+1,row_number,left_horizontal);
                }
                else if (Board[i][j] == Board[i][j+1] && Board[i][j+1] == Board[i][j+2])
                {
                    if (j >= 5)
                        continue;
                    right_horizontal = 3;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs right horizontally.\n",j+1,row_number,right_horizontal);
                }
                else if (Board[i][j] == Board[i-1][j] && Board[i-1][j] == Board[i-2][j])
                {
                    up_vertical = 3;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs up vertically.\n",j+1,row_number,up_vertical);
                }
                else if (Board[i][j] == Board[i-1][j+1] && Board[i-1][j+1] == Board[i-2][j+2])
                {
                    if (j >= 5)
                        continue;
                    right_up_diagonal = 3;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs right up diagonally.\n",j+1,row_number,right_up_diagonal);
                }
                else if (Board[i][j] == Board[i+1][j-1] && Board[i+1][j-1] == Board[i+2][j-2])
                {
                    if (j <= 1)
                        continue;
                    left_down_diagonal = 3;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs left down diagonally.\n",j+1,row_number,left_down_diagonal);
                }
                else if (Board[i][j] == Board[i-1][j-1] && Board[i-1][j-1] == Board[i-2][j-2])
                {
                    if (j <= 1)
                        continue;
                    left_up_diagonal = 3;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs left up diagonally.\n",j+1,row_number,left_up_diagonal);
                }
                else if (Board[i][j] == Board[i+1][j+1] && Board[i+1][j+1] == Board[i+2][j+2])
                {
                    if (j >= 5)
                        continue;
                    right_down_diagonal = 3;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs right down diagonally.\n",j+1,row_number,right_down_diagonal);
                }
                else if (Board[i][j] == Board[i][j-1])
                {
                    if (left_horizontal == 3 || j == 0)
                        continue;
                    left_horizontal = 2;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs left horizontally.\n",j+1,row_number,left_horizontal);
                }
                else if (Board[i][j] == Board[i][j+1])
                {
                    if (right_horizontal == 3 || j == 5)
                        continue;
                    right_horizontal = 2;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs right horizontally.\n",j+1,row_number,right_horizontal);
                }
                else if (Board[i][j] == Board[i-1][j])
                {
                    if (up_vertical == 3)
                        continue;
                    up_vertical = 2;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs up vertically.\n",j+1,row_number,up_vertical);
                }
                else if (Board[i][j] == Board[i+1][j-1])
                {
                    if (left_down_diagonal == 3 || j == 0)
                        continue;
                    left_down_diagonal = 2;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs left down diagonally.\n",j+1,row_number,left_down_diagonal);
                }
                else if (Board[i][j] == Board[i-1][j-1])
                {
                    if (left_up_diagonal == 3 || j == 0)
                        continue;
                    left_up_diagonal = 2;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs left up diagonally.\n",j+1,row_number,left_up_diagonal);
                }
                else if (Board[i][j] == Board[i-1][j+1])
                {
                    if (right_up_diagonal == 3 || j == 5)
                        continue;
                    right_up_diagonal = 2;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs right up diagonally.\n",j+1,row_number,right_up_diagonal);
                }
                else if (Board[i][j] == Board[i+1][j+1])
                {
                    if (right_down_diagonal == 3 || j == 5)
                        continue;
                    right_down_diagonal = 2;
                    //printf("box (%d,%d) corresponds to an alignment of %d discs right down diagonally.\n",j+1,row_number,right_down_diagonal);
                }
            }
        }
    }
}


//Written by Murad Baghirli, Nijat Zeynalli
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
                    if (j <= 2 && Board[i+1][j-3] == ' ')
                        continue;
                    left_horizontal = 3;
                    printf("Player %c should play the column %d to win\n",disc,j-2);
                }
                else if (Board[i][j] == Board[i][j-1] && Board[i+1][j-3] != ' ')
                {
                    if (left_horizontal == 3 || j <= 1)
                        continue;
                    left_horizontal = 2;
                    printf("Player %c should play the column %d\n",disc,j-1);
                }
                if (Board[i][j] == Board[i][j+1] && Board[i][j+1] == Board[i][j+2])
                {
                    if (j >= 4)
                        continue;
                    right_horizontal = 3;
                    printf("Player %c should play the column %d to win\n",disc,j+4);
                    break;
                }
                else if (Board[i][j] == Board[i][j+1])
                {
                    if (right_horizontal == 3 || j >= 5)
                        continue;
                    right_horizontal = 2;
                    printf("Player %c should play the column %d\n",disc,j+3);
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
                }
                if (Board[i][j] == Board[i-1][j+1] && Board[i-1][j+1] == Board[i-2][j+2])
                {
                    if (j >= 4)
                        continue;
                    right_up_diagonal = 3;
                    printf("Player %c should play the column %d to win\n",disc,j+4);
                    break;
                }
                else if (Board[i][j] == Board[i-1][j+1])
                {
                    if (right_up_diagonal == 3 || j >= 5)
                        continue;
                    right_up_diagonal = 2;
                    printf("Player %c should play the column %d\n",disc,j+3);
                }
                if (Board[i][j] == Board[i+1][j-1] && Board[i+1][j-1] == Board[i+2][j-2])
                {
                    if (j <= 2)
                        continue;
                    left_down_diagonal = 3;
                    printf("Player %c should play the column %d to win\n",disc,j-2);
                    break;
                }
                else if (Board[i][j] == Board[i+1][j-1])
                {
                    if (left_down_diagonal == 3 || j <= 1)
                        continue;
                    left_down_diagonal = 2;
                    printf("Player %c should play the column %d\n",disc,j-1);
                }
                if (Board[i][j] == Board[i-1][j-1] && Board[i-1][j-1] == Board[i-2][j-2])
                {
                    if (j <= 2)
                        continue;
                    left_up_diagonal = 3;
                    printf("Player %c should play the column %d to win\n",disc,j-2);
                    break;
                }
                else if (Board[i][j] == Board[i-1][j-1])
                {
                    if (left_up_diagonal == 3 || j <= 1)
                        continue;
                    left_up_diagonal = 2;
                    printf("Player %c should play the column %d\n",disc,j-1);
                }
                if (Board[i][j] == Board[i+1][j+1] && Board[i+1][j+1] == Board[i+2][j+2])
                {
                    if (j >= 4)
                        continue;
                    right_down_diagonal = 3;
                    printf("Player %c should play the column %d to win\n",disc,j+4);
                    break;
                }
                else if (Board[i][j] == Board[i+1][j+1])
                {
                    if (right_down_diagonal == 3 || j >= 5)
                        continue;
                    right_down_diagonal = 2;
                    printf("Player %c should play the column %d\n",disc,j+3);
                }
            }
        }
    }
}


//function that generates a random number
int ra()
{
    srand(time(0));
    int rn = rand()% 7 + 1;

    return rn;
}

void computer(char Board[ROWS][COLUMNS], int column, char disc)
{
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
}
}


//The main function
int main(void)
{
    int column,choice;
    char disc;
    printf("Which type of game do you want?\n1.computer vs human\n2.human vs human(1 or 2)\n");
    scanf("%d",&choice);
    if (choice==2){
    printf("Enter the first player's disc: ");
    scanf(" %c",&disc);  
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
        count_aligned_disc(Board);
        improve_advice(Board,disc);
    }
    }


    else if (choice==1){

    printf("Enter your disc(* or o): ");
    scanf(" %c",&disc);  
    while (!Win())
    {                 
        printf("\nEnter the column between [1-7] where you want to mark: ");
        scanf("%d",&column);
        while (1)
        {
            if(column<1 || column>7)
            {
                printf("Column %d doesn't exist. Enter another column between [1-7] where you want to mark: ",column,disc);
                scanf("%d",&column);
            }
            else
            {
                break;
            }
        }
        if(disc=='*'){
        if (disc == '*')
        {
            drop_disc(Board,column,disc);
            disc = 'o';
        }
        else
        {
            int a=ra();
            computer(Board,a, disc);
            disc = '*';
        }
        print_board(Board);
    }
    if(disc=='o'){
        if (disc == '*')
        {
            int a=ra();
            computer(Board,a,disc);
            disc = 'o';
        }
        else
        {
            drop_disc(Board,column,disc);
            disc = '*';
        }
        
    }
    printf("\n");
    print_board(Board);
    }
}
}