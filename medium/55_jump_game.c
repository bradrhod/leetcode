#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize)
{
    int i=0;
    int maxReach = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(i > maxReach) return false;
        maxReach = (maxReach > i + nums[i]) ? maxReach : i + nums[i];
    }
    return true;
}

int main()
{
    int nums[] = { 2, 3, 1, 1, 4};
    int numsSize = 5;
    bool result = canJump(nums, numsSize);
    printf("result : %b\n", result);
    int nums2[] = { 3, 2, 1, 0, 4};
    int nums2Size = 5;
    result = canJump(nums2, nums2Size);
    printf("result : %b\n", result);
    return 0;
}
