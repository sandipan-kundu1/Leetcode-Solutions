class Solution {
public:
    double myPow(double x, int n) {
        double ans=1,y=abs(x);
        int m=abs(n);
        while(m>0){
            if(m % 2 !=0){
                m = m-1;
                ans= ans* y;
            }
            else{
                m= m / 2;
                y= y* y;
            }
        }
        if(n<0){
            ans=1/ans;
            if(x<0){
                if(abs(n)%2!=0)
                return (-1)*ans;
                return ans;
            }
        }
        if(x<0){
                if(abs(n)%2!=0)
                return (-1)*ans;
                return ans;
            }
            return ans;
    }
};