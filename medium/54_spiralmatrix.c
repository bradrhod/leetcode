#include <stdlib.h>
#include <stdio.h>

int printMatrix ( int ** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    for(int r = 0; r < matrixSize; r++)
    {
        printf("[ ");
        for( int c = 0; c < *matrixColSize; c++)
        {
            printf(" %d, ", matrix[r][c]);
        }
        printf("] \n");
    }
    return 0;
}

int printRes( int* result, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d", result[i]);
    }
    return 0;
}

int* spiralOrder( int ** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int row = 0;
    int col = 0;
    int* res = malloc( matrixSize * *matrixColSize * sizeof(int));
    int maxrow = matrixSize;
    int maxcol = *matrixColSize;
    int minrow = 0;
    int mincol = 0;
    int rdir = 0;
    int cdir = 1;
    for(int i = minrow; i < matrixSize * *matrixColSize; i++)
    {
        res[i] = matrix[row][col];
        if ( col == maxcol - 1 && cdir == 1)
        {
            // right side - go down
            rdir = 1;
            cdir = 0;
            minrow++;
        }
        else if (row == maxrow - 1 && rdir == 1)
        {
            // bottom - go left
            rdir = 0;
            cdir = -1;
            maxcol--;

        }
        else if( col == mincol && cdir == -1)
        {
            // left side - go up
            rdir = -1;
            cdir = 0;
            maxrow--;
        }
        else if (row == minrow && rdir == -1)
        {
            // top - go right
            rdir = 0;
            cdir = 1;
            mincol++;
        }
        row = row + rdir;
        col = col + cdir;

    }
    *returnSize = matrixSize * *matrixColSize;
    return res;
}

int main()
{
    int rows = 3;
    int cols = 3;
    int returnSize;
    int* ret;
    int **matrix = malloc(rows * sizeof(int*));
    matrix[0] = malloc(cols * sizeof(int));
    matrix[1] = malloc(cols * sizeof(int));
    matrix[2] = malloc(cols * sizeof(int));

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    printMatrix(matrix, rows, &cols, &returnSize);
    printf("\n");
    ret = spiralOrder(matrix, rows, &cols, &returnSize);
    printf("\n");
    printRes(ret, returnSize);

    return 0;
}
