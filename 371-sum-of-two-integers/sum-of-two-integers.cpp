class Solution {
public:
    int getSum(int a, int b) {
        int sum=0,carry=1;
        while(carry){
            sum=a^b;
            carry=(a&b)<<1;
            a=sum;
            b=carry;
        }
        return sum;
    }
};