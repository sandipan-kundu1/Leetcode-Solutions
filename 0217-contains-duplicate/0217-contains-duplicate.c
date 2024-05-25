int compareIntegers(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
bool containsDuplicate(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return false;  // No duplicates in an empty or single-element array
    }

    // Sort the array to bring duplicates closer
    qsort(nums, numsSize, sizeof(int), compareIntegers);

    // Check for duplicates after sorting
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;  // Found a duplicate
        }
    }

    return false;  // No duplicates found
}