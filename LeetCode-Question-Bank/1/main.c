#include <stdio.h>
#include <malloc.h>

int main()
{
    int *twoSum(int *nums, int numsSize, int target, int *returnSize);
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;
    int *result = twoSum(nums, 4, target, &returnSize);
    printf("%d %d\n", result[0], result[1]);
    return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *result = (int *)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}
