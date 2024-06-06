class Solution {
public:
    int countPrimes(int n) { //Sieve of Eratosthenes TC:O(N*log(logN)) SC:O(N)
        if(n<2)
        return 0;
        int prime[n];
        for(int i=2;i<n;i++)
        prime[i]=1;
        int cnt=n-2;
        for(int i=2;i*i<n;i++){
            for(int j=i*i;j<n;j=j+i){
                if(prime[j]==1){
                prime[j]=0;
                cnt--;
                }
            }
        }
        // for(int i=2;i<n;i++){
        //     if(prime[i]==1)
        //     cout<<i<<' ';
        // }
        return cnt;
    }
};