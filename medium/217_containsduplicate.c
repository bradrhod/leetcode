#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int partition( int * arr, int low, int high, int pivot)
{
    int i = low;
    int j = low;
    int temp;
    while ( i <= high )
    {
        if(arr[i] > pivot){
            i++;
        }
        else {
            // Swap
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;

        }
    }
    return j - 1;
}


void quicksort(int* arr, int low, int high)
{
    if(low < high)
    {
        int randIdx = low + rand() % (high - low + 1);
        int t = arr[randIdx];
        arr[randIdx] = arr[high];
        arr[high] = t;

        int pivot = arr[high];
        int pos = partition( arr, low, high, pivot);

        quicksort(arr, low , pos - 1 );
        quicksort(arr, pos+1, high );

    }
}

bool containsDuplicate(int * nums, int numsSize)
{
    bool dup = false;
    quicksort( nums, 0, numsSize - 1);
    for( int i = 0; (i < numsSize - 1) && dup == false; i++)
    {
        if(nums[i]==nums[i+1])
            dup = true;
    }
    return dup;
}


int main()
{
    int nums1[] = {1, 2, 3, 1};

    bool result;
    result = containsDuplicate(nums1, 4);
    return 0;

}
