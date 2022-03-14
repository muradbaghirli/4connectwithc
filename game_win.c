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
