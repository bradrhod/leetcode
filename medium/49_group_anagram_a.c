#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

// set  atable size
#define TABLE_SIZE  10007
//create the table node data type
typedef struct Node {
    char* key;
    int groupIndex;
    struct Node* next;
} Node;


// hashtqable function
unsigned long djb( const char* str)
{
    unsigned long hash = 5381;
    int c = 0;
    while(( c = *str++ ))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int hashFunc(const char* str)
{
    return djb(str) % TABLE_SIZE;
}
// insert a hashtable entry

// lookup a hashtable entry.
int cmp_char( const void* a, const void* b)
{
    return(*(const char*) a - *(const char* ) b);
}

char* sortedCopy( char* str)
{
    int len = strlen(str);
    char* res = malloc( len + 1 );
    strcpy(res, str);
    qsort(res, len, sizeof(char), cmp_char );
    return res;
}

void hashInsert(Node** table, char* str, int groupIndex)
{
    int hash = hashFunc(str);
    Node* node = malloc(sizeof(Node));
    node->key = strdup(str);
    node->groupIndex = groupIndex;
    node->next = table[hash];
    table[hash] = node;
}

int hashlookup(Node** table, char* str)
{
    int hash = hashFunc(str);
    Node* cur = table[hash];
    while(cur != NULL )
    {
        if(strcmp(cur->key, str) == 0)
            return cur->groupIndex;

        cur = cur->next;
    }
    return -1;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char*** res = malloc(strsSize * sizeof(char*));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    Node** table = calloc(TABLE_SIZE, sizeof(Node*));
    int* groupCap = malloc(strsSize * sizeof(int));
    int groupCount = 0;

    //Loop throu strings looking for
    for(int i = 0; i < strsSize; i++)
    {
        char* sorted = sortedCopy(strs[i]);
        int existingGroup = hashlookup(table, sorted);
        if(existingGroup != -1)
        {
            if( (*returnColumnSizes)[existingGroup] == groupCap[existingGroup])
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
    int len = sizeof(strs)/sizeof(strs[0]);
    int returnSize;
    int *returnColumnSizes;
    printarray(strs, len);
    char*** res;
    res = groupAnagrams(strs, len, &returnSize, &returnColumnSizes);
    printRes(res, returnSize, returnColumnSizes);
    return 0;
}
