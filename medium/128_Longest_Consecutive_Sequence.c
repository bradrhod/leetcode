#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if(arg1<arg2) return -1;
    if(arg1>arg2) return 1;
    return 0;
}

int longestConsecutive(int* nums, int numsSize) {
    if(numsSize == 0) return 0;

    qsort(nums, numsSize, sizeof(int), compare_ints);

    int best = 1;
    int cur  = 1;
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i-1])
            continue;
        if(nums[i] == nums[i-1]+1)
        {
            cur++;
            if(cur > best) best = cur;
        } else {
            cur=1;
        }
    }
    return best;

}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int len = sizeof(nums)/sizeof(nums[0]);
    int answer = longestConsecutive(nums, len);
    printf("running %d\n", answer);
    return 0;
}


