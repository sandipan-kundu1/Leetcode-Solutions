void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    // Ensure valid input sizes
    if (nums1 == NULL || nums2 == NULL || m < 0 || n < 0) {
        return;
    }

    int i = m - 1;  // Index for the last element in nums1
    int j = n - 1;  // Index for the last element in nums2
    int k = m + n - 1;  // Index for the last position in nums1

    // Merge nums1 and nums2 into nums1 in sorted order
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}