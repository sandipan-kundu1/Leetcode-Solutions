/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int* ans = NULL;
    int k = 0;

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                k++;
                break;  // Once a match is found, move to the next element in nums1
            }
        }
    }

    ans = (int*)malloc(k * sizeof(int));
    k = 0;  // Reset k for populating the result array

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                ans[k] = nums1[i];
                k++;
                nums2[j] = INT_MIN;  // Mark this element as used in nums2
                break;  // Once a match is found, move to the next element in nums1
            }
        }
    }

    *returnSize = k;
    return ans;
}
