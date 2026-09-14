#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define HASH(x) ((size_t)((uint32_t)(x) * 2654435761u) & mask)
int contains(int x, int *keys, char *used, size_t  mask ) {
    size_t h = HASH(x);
    while(used[h])
    {
        if(keys[h] == x) return 1;
        h = (h + 1) & mask;
    }
    return 0;
}


int longestConsecutive(int* nums, int numsSize)
{
    // the unsigned intger magth makdes sure that negatives hash the same as positives.

    // capacity is next power of 2 >= 2* numsSize
    size_t cap = 1;
    while(cap < (size_t)numsSize*2) cap <<= 1;
    size_t mask = cap - 1;

    int *keys = malloc(cap * sizeof(int));
    char *used = calloc(cap, 1);

    for(int i = 0; i < numsSize; i++)
    {
        size_t h = HASH(nums[i]);
        while((used[h] && keys[h] != nums[i])) h = (h + 1) & mask;
        keys[h] = nums[i];
        used[h] = 1;
    }

    int best = 0;
    for(int i = 0; i < numsSize; i++)
    {
        int x = nums[i];
        if(contains(x-1, keys, used, mask)) continue;  // not the start of run.

        int len = 1;
        while(contains(x+len, keys, used, mask)) len++;
        if(len > best) best = len;
    }

    free(keys);
    free(used);

    return 1;

}



int main()
{

    return 0;
}
