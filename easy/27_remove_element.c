#include <stdio.h>
#include <stdbool.h>

int removeElement(int* nums, int numsSize, int val) {
    int shifted = 0;
    for(int i = 0; i < numsSize - shifted; )
    {
        if(nums[i] == val)
        {
            //remove this value, shift remainng values left 1
            for(int j = i; j < numsSize - shifted - 1; j++)
            {
                nums[j] = nums[j+1];
            }
            shifted++;
        }
        else {
            i++;
        }
    }
    return numsSize-shifted;
}

int main()
{
    int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2};
    int numsSize=8;
    int val = 2;
    removeElement(nums, numsSize, val);

    return 0;
}
