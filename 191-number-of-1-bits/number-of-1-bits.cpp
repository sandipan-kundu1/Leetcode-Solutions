class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n){
            n=n& (n-1);
            cnt++; //clearing rightmost bit in each iteration, counting the iterations to get no of set bits
        }
        return cnt;
    }
};