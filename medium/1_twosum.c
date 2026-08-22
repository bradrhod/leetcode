#include <stdlib.h>
#include <stdio.h>

int printRes(int* res, int RetSize)
{
    printf("Result: [");
    for(int i = 0; i < RetSize; i++)
    {
        printf("%d, ", res[i]);
    }
    printf("]\n");
    return 0;
}

#define TABLE_SIZE 10007   // a prime, comfortably bigger than numsSize's max (10^4

typedef struct Node {
    int value;
    int index;
    struct Node* next;
} Node;

int hashFunc(int value)
{
    int h = value % TABLE_SIZE;
    if ( h < 0 ) h += TABLE_SIZE;
    return h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    Node* table[TABLE_SIZE] = {0};


    for ( int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int h = hashFunc(complement);
        for(Node * cur = table[h]; cur != NULL; cur = cur->next)
        {
            if(cur->value == complement)
            {
                int* res = malloc(2 * sizeof( int ));
                res[0] = cur->index;
                res[1] = i;
                *returnSize = 2;
                return res;
            }
        }
        // not found yet.
        int hi = hashFunc(nums[i]);
        Node* node = malloc(sizeof(Node));
        node->value = nums[i];
        node->index = i;
        node->next = table[hi];
        table[hi] = node;
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums1[] = {2, 7, 11, 15 };
    int t1 = 9;
    int retSize = 0;
    int* res;
    res = twoSum(nums1, 4, t1, &retSize);
    printRes(res, retSize);
    int nums2[] = {3,2,4};
    int t2 = 6;
    res = twoSum(nums2, 3, t2, &retSize);
    printRes(res, retSize);
    return 0;
}
