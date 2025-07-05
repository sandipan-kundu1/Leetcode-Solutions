class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        long long num;
        while(n)
        {
            num=*s.begin();
            n--;
            s.erase(num);
            for(auto i:{2,3,5})
            s.insert(num*i);
        }
        return (int)num;
    }
};