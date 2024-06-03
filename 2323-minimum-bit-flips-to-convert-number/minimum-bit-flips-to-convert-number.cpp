class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr= start^goal;
        int temp=xorr,len=0,cnt=0;
        while(temp!=0){
            temp=temp/2;
            len++;
        }
        for(int i=0;i<len;i++){
            if((xorr & (1<<i)))
            cnt++;

        }
        return cnt;
    }
};