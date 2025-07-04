class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        bool neg=false;
        long long temp=x;
        if(x<0)
        {
            neg=true;
            temp=-temp;
        }
        int rem;
        while(temp)
        {
            rem=temp%10;
            rev=rev*10+rem;
            temp=temp/10;
        }
        if(rev>INT_MAX)
        return 0;
        if(neg)
        rev=-rev;
        if(rev<INT_MIN)
        return 0;
        return (int)rev;
    }
};