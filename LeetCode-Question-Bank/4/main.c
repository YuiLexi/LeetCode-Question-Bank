#include <stdio.h>
#include <malloc.h>

int main()
{
    double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);
    printf("程序开始!!!\n");
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    printf("中位数为：%f\n", findMedianSortedArrays(nums1, 0, nums2, 2));
    printf("程序结束!!!\n");
    return 0;
}
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int *nums = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    int index1 = 0;
    int index2 = 0;
    int i = 0;
    while (index1 < nums1Size && index2 < nums2Size && i < (nums1Size + nums2Size))
    {
        if (nums1[index1] < nums2[index2])
        {
            nums[i] = nums1[index1];
            index1++;
        }
        else
        {
            nums[i] = nums2[index2];
            index2++;
        }
        i++;
    }
    while (index1 < nums1Size && i < (nums1Size + nums2Size))
    {
        nums[i] = nums1[index1];
        index1++;
        i++;
    }
    while (index2 < nums2Size && i < (nums1Size + nums2Size))
    {
        nums[i] = nums2[index2];
        index2++;
        i++;
    }
    if ((nums1Size + nums2Size) % 2 == 0)
    {
        return (double)(nums[(nums1Size + nums2Size) / 2 - 1] + nums[(nums1Size + nums2Size) / 2]) / 2.0;
    }
    else
    {
        return (double)nums[(nums1Size + nums2Size) / 2];
    }
}