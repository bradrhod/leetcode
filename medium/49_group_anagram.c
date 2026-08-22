#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void printarray(char** strs, int strsSize)
{
    printf("array: { ");
    for(int i = 0; i < strsSize; i++)
    {
       printf("%s, ", strs[i]);
    }
    printf("}\n");
}

void printRes(char*** res, int resultSize, int* resultColumnSizes)
{
    printf("results: { ");

    for(int i = 0; i < resultSize; i++)
    {
        printf("{ ");
        for( int j = 0; j < resultColumnSizes[i]; j++)
        {
            printf(" %s, ", res[i][j]);

        }
        printf("}, ");

    }
    printf(" }\n}");
}

#define TABLE_SIZE 10007   // a prime, comfortably bigger than numsSize's max (10^4
typedef struct Node {
    char* key;
    int groupIndex;
    struct Node* next;
} Node;

unsigned long djb2( const char* str)
{
    unsigned long hash = 5381;
    int c;
    while(( c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int hashFunc(const char* str)
{
    return djb2(str) % TABLE_SIZE;
}

int hashLookup( Node** table, const char* key)
{
    int h = hashFunc(key);
    for(Node* cur = table[h]; cur!= NULL; cur = cur->next)
    {
        if(strcmp(cur->key, key) == 0)
            return cur->groupIndex;
    }
    return -1;
}

void hashInsert(Node** table, const char* key, int groupIndex)
{
    int h = hashFunc(key);
    Node* node = malloc(sizeof(Node));
    node->key = strdup(key);
    node->groupIndex = groupIndex;
    node->next = table[h];
    table[h] = node;
}


int cmpchar(const void* a, const void* b)
{
    return(*(const char*)a - *(const char*)b);
}

char* sortedCopy(char* s)
{
    int n = strlen(s);
    char* copy = malloc(n+1);
    strcpy(copy, s);

    qsort(copy, n, sizeof(char), cmpchar);

    return copy;
}


char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char*** res = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc( strsSize * sizeof(int) );
    int* groupCap = malloc( strsSize * sizeof(int) );
    int groupCount = 0;
    Node** table = calloc(TABLE_SIZE, sizeof(Node*));

    for(int i = 0; i < strsSize; i++)
    {
        char* sorted = sortedCopy(strs[i]);
        int existingGroup = hashLookup(table, sorted);
        if(existingGroup != -1)
        {
            if ((*returnColumnSizes)[existingGroup] == groupCap[existingGroup])
            {
                groupCap[existingGroup] *= 2;
                res[existingGroup] = realloc(res[existingGroup], groupCap[existingGroup] * sizeof(char*));
            }
            res[existingGroup][(*returnColumnSizes)[existingGroup]] = strs[i];
            (*returnColumnSizes)[existingGroup]++;
        }
        else
        {
            // brand new group
            groupCap[groupCount] = 4;
            res[groupCount] = malloc(groupCap[groupCount] * sizeof(char*));
            res[groupCount][0] = strs[i];
            (*returnColumnSizes)[groupCount] = 1;
            hashInsert(table, sorted, groupCount);
            groupCount++;
        }
    }
    *returnSize = groupCount;
    return res;
}
int main()
{
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int len = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;
    printarray(strs, len);
    char*** res;
    res = groupAnagrams(strs, len, &returnSize, &returnColumnSizes);
    printRes( res, returnSize, returnColumnSizes);
    return 0;
}

