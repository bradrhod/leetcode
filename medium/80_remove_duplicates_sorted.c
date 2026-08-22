#include <stdio.h>
#include <stdbool.h>

int printarray(int* nums, int numsSize)
{
    printf("[");
    for(int i = 0; i < numsSize; i++)
    {
        printf(" %d, ", nums[i]);
    }
    printf("]\n");
    return 0;
}

int removeDuplicates( int* nums, int numsSize)
{
    if (numsSize <= 2) return numsSize;

    int k = 2; // next write position
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}


int main()
{
    int nums[] = { 1, 1, 1, 2, 2, 3};
    int numlen = 6;
    printf("-- new run");
    printarray(nums, numlen);

    int result = removeDuplicates(nums, numlen);
    printf("result %d\n", result);
    printarray(nums, result);
    int nums2[] = { 0, 0, 0, 0, 1, 1, 1, 2, 3 };
    int nums2len = 9;
    printf("-- new run" );
    printarray(nums2, nums2len);
    result = removeDuplicates(nums2, nums2len);
    printf("result %d \n", result);
    printarray(nums2, result);
    int nums3[] = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
    int nums3len = 9;
    printf("-- new run" );
    printarray(nums3, nums3len);
    result = removeDuplicates(nums3, nums3len);
    printf("result %d \n", result);
    printarray(nums3, result);
    return 0;
}
