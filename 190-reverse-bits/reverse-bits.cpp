class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=0;i<32;i++) {
            int bit=(n>>i) & 1; //storing ith bit
            ans=ans | bit<<(31-i);//adding it to its reverse position by 31-i
        }
        return ans;
    }
};
