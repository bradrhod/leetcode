#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <limits.h>

void printarray(char** strs, int strsSize)
{
    printf("{ ");
    for(int i = 0; i < strsSize; i++)
    {
        printf("%s, ", strs[i]);
    }
    printf("}\n");
}

//Encoede a list of strings to a single string
char* encode(char** strs, int strsSize)
{
    int slen = 0;
    int buflen = 100;
    char* res = malloc(buflen * sizeof(char));
    static const size_t codedSize =  3 * sizeof(int) * 2;
    char codedInt[codedSize];
    for(int i = 0; i < strsSize; i++)
    {
        // create an encoded string delimited by #.  5#Hello
        int len = strlen(strs[i]);
        int sizeCI = snprintf(codedInt, codedSize, "%d", len);
        int totallen = sizeCI + len + 1;
        // realloc some memory if we do not have enough
        while (totallen + slen >= buflen)
        {
            buflen = buflen * 2;
            res = realloc(res, buflen * sizeof(char));
        }
        // append the string.
        memcpy(&res[slen], codedInt, sizeCI);
        res[slen + sizeCI] = '#';
        memcpy(&res[slen + sizeCI + 1], strs[i], len);
        slen = slen + totallen;
    }
    res[slen]=0;
    return res;
}
// Decodes a singe string to a list of strings.
// returns an araray of sizes return sizes
// assumes caller calls free.
char** decode(char* s, int * returnSize)
{
    bool done = false;
    int retSize = 0;
    int proclen = 0;
    int bufsize = 100;
    char** retbuf = malloc(bufsize * sizeof(char*));
    while(!done)
    {

        if(s[proclen] == 0)
        {
            done = true;
        }
        else{
            char* end;
            long length = strtol(&s[proclen], &end, 10);
            proclen = proclen + end - &s[proclen];
            if(s[proclen] != '#')
            {
                //error in string format
                printf("error in string format, missing # in item %d", retSize);
                return NULL;
            }
            proclen++;
            if (retSize == bufsize)
            {
                bufsize = bufsize * 2;
                retbuf = realloc(retbuf, bufsize*sizeof(char*));
            }
            retbuf[retSize] = malloc(length * sizeof(char)+1);
            memcpy(retbuf[retSize], &s[proclen], length);
            retbuf[retSize][length]=0;
            retSize++;
            proclen = proclen + length;

        }
    }
    *returnSize = retSize;
    return retbuf;
}

int main()
{
    char* strs[] = { "Hello", "World"};
    char* res;
    int strsSize = sizeof(strs)/sizeof(char*);
    res = encode( strs, strsSize );
    char** decstring;
    int decstringSize;
    decstring = decode(res, &decstringSize);
    printarray(decstring, decstringSize);
    return 0;
}
