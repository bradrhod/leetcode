#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard( int** board, int boardSize, int* boardColSize)
{
    printf("board: \n");
    for(int i = 0; i < boardSize; i++)
    {
        printf("[ ");
        for(int j = 0; j < *boardColSize; j++)
        {
            printf( "%d, ", board[i][j]);
        }
        printf(" ]\n");
    }
}


void gameOfLife(int** board,  int boardSize, int* boardColSize)
{
    bool done = false;
    bool ownBoard = false;
    int** boardRes = malloc( boardSize * sizeof(int*));
    for( int r = 0; r < boardSize; r++)
    {
        boardRes[r] = malloc(*boardColSize * sizeof(int));
    }
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < *boardColSize; j++)
        {
            // at each location asccess the 8 neighbors and find out their
            int liven = 0;
            for(int ni = -1; ni <= 1; ni++)
            {
                if( i+ni >= 0 && i+ni < boardSize)
                {
                    for( int nj = -1; nj <=1; nj++)
                    {
                        if( j+nj >= 0 && j+nj < *boardColSize)
                        {
                            if(!(ni == 0 && nj == 0))
                                if( board[i+ni][j+nj] == 1)
                                    liven++;
                        }
                    }
                }
            }
            if( liven == 3)
                boardRes[i][j] = 1;
            else if ( liven == 2)
                boardRes[i][j]=board[i][j];
            else
                boardRes[i][j] = 0;
        }
    }
    if (ownBoard){
        for(int r=0; r < boardSize; r++)
            free(board[r]);
        free(board);
    }
    for( int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            board[i][j] = boardRes[i][j];
        }
    }
    free(boardRes);
    ownBoard = true;
    return;
}


int main()
{

    int rows = 4;
    int cols = 3;
    int row0[] = {0, 1, 0};
    int row1[] = {0, 0, 1};
    int row2[] = {1, 1, 1};
    int row3[] = {0, 0, 0};
    int * board[] = { row0, row1, row2, row3};

    gameOfLife(board, rows, &cols);
    return 0;
}
