#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int left = 0;
    int right = numbersSize-1;
    int* res = malloc(sizeof(int*) * 2);
    int total = 0;


    while(left < right)
    {
        total = numbers[left] + numbers[right];
        if(total == target)
        {
            *returnSize = 2;
            res[0] = left+1;
            res[1] = right+1;
            return res;
        }
        else if( total < target)
            left++;
        else right --;
    }
    *returnSize = 0;
    return res;
}

int main()
{
    int numbers[] = {2, 7, 11, 15};
    int numsSize = sizeof(numbers)/sizeof(numbers[0]);
    int returnSize;
    int* res = twoSum(numbers, numsSize, 9, &returnSize);
    printf("res [%d, %d]", res[0], res[1]);
}


