/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) 
{
    bool *result;
    result=(bool*)malloc(candiesSize*sizeof(candies));
    int b,flag=0;
    for(int i=0;i<candiesSize;i++)
    {
        
        b=candies[i]+extraCandies;
        for(int j=0;j<candiesSize;j++)
        {
            if(b>=candies[j])
            flag=1;
            else
            {
                flag=0;
                break;
            }
            
        }
        if(flag==1)
        result[i]=true;
        else
        result[i]=false;
    }
    *returnSize=candiesSize;
    return result;
}