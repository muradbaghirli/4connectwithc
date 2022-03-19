#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Group members: 
    //Ismayil Abdullazada
    //Nihat Babayev
    //Murad Baghirli
    //Nijat Zeynalli

// Exercise 1 was written by Nijat Zeynalli
#define ROWS 6
#define COLUMNS 7

// ' ' = represents no discs 
// '*' represents the red discs
// 'o' = represents the yellow discs

//This 2d-array is the board
char Board[ROWS][COLUMNS] = {
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' '}
                            };
//---------------------------------------------------------------//

// Exercise 2 was written by Nihat Babayev 
void clear()
{
    /*
    This function clears the Connect 4 Board.
    */
    char list_element = ' ';

    //Everytime the game is finished, these loops clean the game board
    for (int row = 0; row < ROWS; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            Board[row][column] = list_element;
        }
    }
}
//---------------------------------------------------------------//

// Exercise 3 was written by Ismayil Abdullazada
void print_board()
{
    /*
    This function prints Connect 4 Board.
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
//---------------------------------------------------------------//

// Exercise 4 was written by Murad Baghirli
bool possible_play(int position)
{
    /*
    This function shows if the player can put his disk on the chosen place.
    : param position: the chosen place to put the disk
    : type position: int 
    : returns: true if the player can put his disk there or false if not
    */
    if (Board[0][position-1] == ' ' && position >= 1 && position <= 7 )
    {
        // valid move
        return true;
    }
    //If player did not enter a valid column number, he/she will be warned to enter a correct one
    else
    {
        // invalid move 
        return false;
    }
}
//---------------------------------------------------------------//

// Exercise 5 was written by Ismayil Abdullazada
void drop_disc(int column, char disc)
{
    /* This function  puts the player's disc into the grid.
    :param column: vertical lines of the grid
    :type column: int
    :param disc: player's disc
    :type disc: char
    */
    for (int row = ROWS-1; row > -1; row--)
    {
        if (possible_play(column))
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
            drop_disc(column,disc);
            break;
        }
    }
}
//---------------------------------------------------------------//

// Exercise 6 was written by Nihat Babayev and Ismayil Abdullazada
void count_aligned_disc()
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
//---------------------------------------------------------------//

// Game winning conditions: 

// Was written by Nihat Babayev
bool horizWin()
{
    /*
    Checks if the player has 4 same disks in one horizontal line."""
    :returns: true or false
    */

    //By using the indexes of the 2d-array for horizontal order this function determines whether anyone has won or not
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (Board[row][col] != ' ')
            {
                if (Board[row][col] == Board[row][col+1] && Board[row][col] == Board[row][col+2] && Board[row][col] == Board[row][col+3])
                {
                   printf("\nPlayer %c has won the game!\n",Board[row][col]);
                   printf("Game Over!\n");
                   return true; 
                }
            }
        }
    }    
    return false;
}

// Was written by Murad Baghirli
bool vertWin()
{
    /*
    Checks if the player has 4 same disks in one vertical line.
    :returns: true or false
    */

    //By using the indexes of the 2d-array for vertical order this function determines whether anyone has won or not
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            if (Board[row][col] != ' ')
            {
                if (Board[row][col] == Board[row+1][col] && Board[row][col] == Board[row+2][col] && Board[row][col] == Board[row+3][col])
                {
                   printf("\nPlayer %c has won!\n",Board[row][col]);
                   printf("Game Over!\n");
                   return true;
                }
            }
        }
    }
    return false;
}

// Was written by Ismayil Abdullazada, Murad Baghirli, Nijat Zeynalli, Nihat Babayev
bool diagWin()
{
    /*
    Checks  if the player has 4 same disks in one diagonal line.
    :returns: true or false
    */

    //The function checks all possible diagonal win conditions by increasing the column index and decreasing or increasing the row index

    //check for starting position of diagonal by going up and to the right
    for (int row = 3; row < ROWS; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (Board[row][col] != ' ')
            {
                if (Board[row][col] == Board[row-1][col+1] && Board[row][col] == Board[row-2][col+2] && Board[row][col] == Board[row-3][col+3])
                {
                   printf("\nPlayer %c has won!\n",Board[row][col]);
                   printf("Game Over!\n");
                   return true;
                }
            }
        }
    }
    //check for starting position of diagonal by going down and to right
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

// Was written by Nijat Zeynalli  
bool Win()
{
    /*
    Checks if one of the players wins.
    :returns: true or false
    */

    if (horizWin(Board) || vertWin(Board) || diagWin(Board))
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------//

// Exercise 7 was written by Murad Baghirli
void recommend_random_column(char disc)
{
    int column;
    srand(time(0));
    column = 1 + rand() % 7;
    if (possible_play(column) == 1)
    {
        printf("Player '%c' should play the column %d\n",disc,column);
    }
    else
    {
        do
        {
            srand(time(0));
            column = 1 + rand() % 7;
        } while (possible_play(column) == 0);
        printf("Player '%c' should play the column %d\n",disc,column);
    }   
}
//---------------------------------------------------------------//

// Exercise 8 was written by Ismayil Abdullazada
void improve_advice(char disc)
{
    //This function gives advice for both players, when they have both 2 or 3 aligned discs
    int left_horizontal=1, right_horizontal=1, up_vertical=1, right_up_diagonal=1, left_down_diagonal=1, left_up_diagonal=1, right_down_diagonal=1;
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
                        continue;
                    }
                    else if (i == ROWS-1 && Board[i][j-3] == ' ')
                    {
                        left_horizontal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j-2);
                    }
                    else if (i < ROWS-1 && Board[i+1][j-3] != ' ')
                    {
                        left_horizontal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j-2);
                    }
                }
                else if (Board[i][j] == Board[i][j-1])
                {
                    if (j <= 2)
                        continue;
                    else if (i == ROWS-1 && Board[i][j-2] == ' ' && (Board[i][j-3] == disc || Board[i][j-3] == ' '))
                    {
                        left_horizontal = 2;
                        printf("Player %c should play the column %d\n",disc,j-1);
                    }
                    else if (i < ROWS-1 && Board[i+1][j-2] != ' ')
                    {
                        left_horizontal = 2;
                        printf("Player %c should play the column %d\n",disc,j-1);
                    }
                }
                if (Board[i][j] == Board[i][j+1] && Board[i][j+1] == Board[i][j+2])
                {
                    if (j >= 4)
                        continue;
                    else if (i == ROWS-1 && Board[i][j+3] == ' ')
                    {
                        right_horizontal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j+4);
                    }
                    else if (i < ROWS-1 && Board[i+1][j+3] != ' ')
                    {
                        right_horizontal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j+4);
                    }
                }
                else if (Board[i][j] == Board[i][j+1])
                {
                    if (j >= 4)
                        continue;
                    else if (i == ROWS-1 && Board[i][j+2] == ' ' && (Board[i][j+3] == disc || Board[i][j+3] == ' '))
                    {
                        right_horizontal = 2;
                        printf("Player %c should play the column %d\n",disc,j+3);
                    }
                    else if (i < ROWS-1 && Board[i+1][j+2] != ' ')
                    {
                        right_horizontal = 2;
                        printf("Player %c should play the column %d\n",disc,j+3);
                    }
                }
                if (Board[i][j] == Board[i-1][j] && Board[i-1][j] == Board[i-2][j])
                {
                    if (Board[i-3][j] != ' ')
                        continue;
                    up_vertical = 3;
                    printf("Player %c should play the column %d to win\n",disc,j+1);
                }
                else if (Board[i][j] == Board[i-1][j])
                {
                    if (Board[i-2][j] != ' ')
                    {
                        continue;
                    }
                    up_vertical = 2;
                    printf("Player %c should play the column %d\n",disc,j+1);
                }
                if (Board[i][j] == Board[i-1][j+1] && Board[i-1][j+1] == Board[i-2][j+2])
                {
                    if (i <= 2 || j >= 4)
                        continue;
                    else if (Board[i-2][j+3] != ' ')
                    {
                        right_up_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j+4);
                    }
                }
                else if (Board[i][j] == Board[i-1][j+1])
                {
                    if (i <= 2 || j >= 4)
                        continue;
                    else if (Board[i-1][j+2] != ' ')
                    {
                        right_up_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j+3);
                    }
                }
                if (Board[i][j] == Board[i+1][j-1] && Board[i+1][j-1] == Board[i+2][j-2])
                {
                    if (i >= 3 || j <= 2)
                        continue;
                    else if (Board[i+2][j-3] != ' ')
                    {
                        left_down_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j-2);
                    }
                }
                else if (Board[i][j] == Board[i+1][j-1])
                {
                    if (i >= 3 || j <= 2)
                        continue;
                    else if (Board[i+1][j-2] != ' ')
                    {
                        left_down_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j-1);
                    }
                }
                if (Board[i][j] == Board[i-1][j-1] && Board[i-1][j-1] == Board[i-2][j-2])
                {
                    if (i <= 2 || j <= 2)
                        continue;
                    else if (Board[i-2][j-3] != ' ')
                    {
                        left_up_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j-2);
                    }
                }
                else if (Board[i][j] == Board[i-1][j-1])
                {
                    if (i <= 2 || j <= 2)
                        continue;
                    else if (Board[i-1][j-2] != ' ')
                    {
                        left_up_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j-1);
                    }
                }
                if (Board[i][j] == Board[i+1][j+1] && Board[i+1][j+1] == Board[i+2][j+2])
                {
                    if (i >= 3 || j >= 4)
                        continue;
                    else if (Board[i+2][j+3] != ' ')
                    {
                        right_down_diagonal = 3;
                        printf("Player %c should play the column %d to win\n",disc,j+4);
                    }
                }
                else if (Board[i][j] == Board[i+1][j+1])
                {
                    if (i >= 3 || j >= 4)
                        continue;
                    else if (Board[i+1][j+2] != ' ')
                    {
                        right_down_diagonal = 2;
                        printf("Player %c should play the column %d\n",disc,j+3);
                    }
                }
            }
        }
    }
    if (left_horizontal == 1 && right_horizontal == 1 && up_vertical == 1 && right_up_diagonal == 1 && left_down_diagonal == 1 && left_up_diagonal == 1 && right_down_diagonal == 1)
        recommend_random_column(disc);
}
//---------------------------------------------------------------//

// Exercise 9 was written by Nihat Babayev
void computer_play()
{
    //This function makes computer play versus human
    int column;
    char disc = '*';
    srand(time(0));
    column = 1 + rand() % 7;
    if (possible_play(column))
    {
        drop_disc(column,disc);
    }
    else
    {
        do
        {
            srand(time(0));
            column = 1 + rand() % 7;
        } while (!possible_play(column));
        drop_disc(column,disc);
    }   
}
//---------------------------------------------------------------//

// The main function was written by Nijat Zeynalli
int main(void)
{
    char answer;
    do
    {
        int column,choice;
        char disc;
        //In this part user selects to play versus another player or computer
        printf("Which one do you want to play? human vs human || human vs computer (answer by 1 or 2 respectively): ");
        scanf("%d",&choice);
        if (choice == 1)
        {
            printf("\nEnter the first player's disc: ");
            scanf(" %c",&disc); 
            print_board();
            printf("\n"); 
            while (!Win())
            {                
                printf("Player '%c' enter the column between [1-7] where you want to mark: ",disc);
                scanf("%d",&column);
                printf("\n");
                while (1)
                {
                    if(column < 1 || column > 7)
                    {
                        printf("Column %d doesn't exist. Player '%c' enter another column between [1-7] where you want to mark: ",column,disc);
                        scanf("%d",&column);
                    }
                    else
                        break;
                }
                if (disc == '*')
                {
                    drop_disc(column,disc);
                    disc = 'o';
                    improve_advice(disc);
                }
                else
                {
                    drop_disc(column,disc);
                    disc = '*';
                    improve_advice(disc);
                }
                print_board();
                printf("\n");
                count_aligned_disc();
            }
        }
        else if (choice == 2)
        {
            print_board();
            printf("\n"); 
            while (!Win())
            {
                printf("Enter the column between [1-7] where you want to mark: ");
                scanf("%d",&column);
                printf("\n");
                while (1)
                {
                    if(column < 1 || column > 7)
                    {
                        printf("Column %d doesn't exist. Enter another column between [1-7] where you want to mark: ",column);
                        scanf("%d",&column);
                    }
                    else
                        break;
                }
                disc = 'o';
                drop_disc(column,disc);
                print_board();
                printf("\n");
                if (Win())
                    break;
                if (disc == 'o')
                    improve_advice(disc);
                disc = '*';
                computer_play(column);
                print_board();
                printf("\n");
            }
        }
        printf("\nDo you want to play again (y or n): ");
        scanf(" %c",&answer);
        clear();
    }   while (answer == 'y');
}
//---------------------------------------------------------------//
