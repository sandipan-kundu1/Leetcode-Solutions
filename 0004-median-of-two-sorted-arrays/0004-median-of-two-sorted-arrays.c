double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m,n,temp,r;
    double med,*res;
    m=nums1Size;
    n=nums2Size;
    r=m+n;
    res=(double*)malloc((m+n)*sizeof(double));
    /*for(i=0;i<m+n;i++)
    {
        if(i<m)
        {
            res[i]=nums1[i];
        }
        else
        res[i]=nums2[i-m];
    }
    for(i=0;i<r/2;i++)
    {
        if(res[i]>res[i+1])
        {
            temp=res[i];
            res[i]=res[i+1];
            res[i+1]=temp;
        }
    }*/
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            res[k++] = nums1[i++];
        } else {
            res[k++] = nums2[j++];
        }
    }

    // Copy remaining elements from nums1 (if any)
    while (i < m) {
        res[k++] = nums1[i++];
    }

    // Copy remaining elements from nums2 (if any)
    while (j < n) {
        res[k++] = nums2[j++];
    }
    if(r%2==0)
    med=(res[r/2]+res[r/2-1])/2.0;
    else
    med=res[(r-1)/2];
    return med;
}