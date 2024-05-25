/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int *ans,j=0;
    ans=(int*)malloc(wordsSize*sizeof(int));
    for(int i=0;i<wordsSize;i++)
    {
        for(int k=0;words[i][k]!='\0';k++)
        {
            if(words[i][k]==x)
            {
                ans[j]=i;
                j++;
                break;
            }
            
        }
        
    }
    *returnSize=j;
    return ans;
}