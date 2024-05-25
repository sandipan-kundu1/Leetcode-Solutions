int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) 
{
    int max=0,b;
    for(int i=0;i<accountsSize;i++)
    {
        b=0;
        for(int j=0;j<accountsColSize[i];j++)
        {
            
            b+=accounts[i][j];
        }
        if(b>max)
        max=b;
    }
    return max;
}