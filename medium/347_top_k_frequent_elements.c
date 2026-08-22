#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray( int * nums, int numsSize)
{
    printf("{ ");
    for(int i = 0; i< numsSize; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("} \n");

}

#define TABLE_SIZE 10007
int hashfunc(int value)
{
    int h = value % TABLE_SIZE;
    if( h < 0 ) h += TABLE_SIZE;
    return h;
}


typedef struct freqNode{
    int value;
    int count;
    struct freqNode* next;
} freqNode;

int* topKFrequent( int* nums, int numsSize, int k, int* returnSize)
{
    freqNode** table = calloc(TABLE_SIZE, sizeof(freqNode*));
    bool found = false;

    // loop through the nums, and add them to the hashtable, incrementing counts
    for(int i = 0; i < numsSize; i++)
    {
        found = false;
        int h = hashfunc(nums[i]);
        freqNode* cur = table[h];
        while(cur != NULL)
        {
            if (cur->value == nums[i])
            {
                // add to the count
                cur->count++;
                found=true;
                break;
            }
            cur = cur->next;
        }
        if(found == false)
        {
            //create a new hashtable entry
            freqNode* node = malloc(sizeof(freqNode));
            node->value = nums[i];
            node->count = 1;
            node->next = table[h];
            table[h] = node;
        }
    }

    // add the frequencies
    int ** buckets = calloc(numsSize+1, sizeof(int*));
    int* bucketSizes = calloc(numsSize+1, sizeof(int));
    int* bucketCap = calloc(numsSize+1, sizeof(int));

    for(int h=0; h < TABLE_SIZE; h++)
    {

        for( freqNode* cur = table[h]; cur != NULL; cur = cur->next)
        {
            int f = cur->count;
            if(bucketSizes[f] == bucketCap[f])
            {
                bucketCap[f] = bucketCap[f] == 0 ? 4 : bucketCap[f] * 2;
                buckets[f] = realloc(buckets[f], bucketCap[f] * sizeof(int));
            }
            buckets[f][bucketSizes[f]] = cur->value;
            bucketSizes[f]++;
        }
    }

    // now count the largest bucketsizes until we have k buckets.
    int* res = malloc(k*sizeof(int));
    int resultCount = 0;
    for(int f = numsSize; f >= 1 && resultCount < k; f--)
    {
        for(int j = 0; j < bucketSizes[f] && resultCount < k; j++)
        {
            res[resultCount++] = buckets[f][j];
        }
    }
    *returnSize = resultCount;
    return res;
}

int main ()
{
    int a[] = { 1, 1, 2, 1, 2, 3};
    int len = sizeof(a)/sizeof(int);
    printArray(a, len);
    int* ret;
    int returnSize;
    ret =  topKFrequent(a, len, 2, &returnSize);
    return 0;
}
