#include <stdlib.h>

int * productExceptSelf(int * nums, int numsSize, int* returnSize)
{
    // compute the prefix, using left to riht of arra
    int* ret = malloc(numsSize * sizeof(int));
    int suffix[numsSize];
    int runSuffix = 1;
    for (int i = 0; i < numsSize; i++)
    {
        ret[i] = runSuffix;
        runSuffix = runSuffix * nums[i];
    }
    // compute the suffix, using right to left
    int runPrefix = 1;
    for (int i = numsSize - 1 ; i >= 0 ; i--)
    {
        ret[i] *= runPrefix;
        runPrefix = runPrefix * nums[i];
    }
    *returnSize = numsSize;
    return ret;
}

int main()
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums)/sizeof(int);
    int returnSize=0;
    int* res;
    res = productExceptSelf(nums, numsSize, &returnSize);
    int nums2[] = {-1, 1, 0, -3, 3};
    int numsSize2 = sizeof(nums2)/sizeof(int);
    res = productExceptSelf(nums2, numsSize2, &returnSize);
    return 0;
}
