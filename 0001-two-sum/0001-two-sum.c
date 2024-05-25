#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                // Allocate memory for the result array
                int* result = (int*)malloc(2 * sizeof(int));
                // Set values in the result array
                result[0] = i;
                result[1] = j;
                // Set the size of the result array
                *returnSize = 2;
                return result;
            }
            
        }
    }
    
    // If no solution is found
    *returnSize = 0;
    return NULL;
}

