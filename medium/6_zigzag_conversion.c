#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int printarray(char s[][100], int rows, int cols)
{
    printf("printing result;\n");
    for( int row = 0; row < rows; row++ )
    {
        printf("row: %d ", row);
        for( int col = 0; col < cols; col++)
        {
            printf( "%c, ", s[row][col]);
        }
        printf("\n");

    }
    return 1;
}


char* convert(char* s, int numRows)
{
    int pos=0;
    int len = strlen(s);

    if ( numRows <= 1 || numRows >= len)
    {
        char *result = malloc(len+1);
        strcpy(result, s);
        return result;
    }

    char * result = malloc(len+1);
    int cycleLen = 2* (numRows -1);

    for(int row = 0; row < numRows; row++)
    {
        for(int i = row; i < len; i += cycleLen)
        {
            result[pos++] = s[i];   // thd down character
            int diag = i + cycleLen - 2 * row;
            if(row != 0 && row != numRows - 1 && diag < len)
                result[pos++] = s[diag];
        }

    }
    result[pos] = '\0';
    return result;
}



int main(){
    char str1[100] = "PAYPALISHIRING";
    char* result = convert(str1, 3);
    printf("result: %s\n", result );
    result  = convert(str1, 4);
    printf("result2: %s\n", result);

    return 0;
}



