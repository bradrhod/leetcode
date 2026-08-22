#include <stdio.h>

int merge_sorted(int* nums1, int nums1Size, int* nums2, int nums2Size, int n)
{
    int j = 0;
    for( int i = 0; i < nums1Size; i++)
    {
        if(nums1[i] == 0)
        {
            nums1[i] = nums2[j];
            j++;
        }
    }
    return 0;
}

int print_array(int* array, int array_size)
{
    printf("[");
    for( int i = 0; i < array_size; i++)
    {
        printf(" %d,", array[i]);
    }
    printf("]");
    return 0;
}

int main()
{
    //test 1
    int nums1[] =  { 1, 2, 3, 0, 0, 0};
    int nums1len = 6;
    int nums2[] = { 2, 5, 6};
    int nums2len = 3;

    merge_sorted(nums1, nums1len, nums2, nums2len, 0);
    print_array(nums1, nums1len);

    // test 2
    int nums3[] = {1};
    int nums3len = 1;
    int nums4[] = {};
    int nums4len = 0;
    merge_sorted(nums3, nums3len, nums4, nums4len, 0);
    print_array(nums3, nums3len);

    return 0;
}
