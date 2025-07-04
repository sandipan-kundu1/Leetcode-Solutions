class Solution {
public:
    int next(int n)
    {
        int sum=0,digit;
        while(n)
        {
            digit=n%10;
            sum+=digit*digit;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n!=1 && !visited.count(n))
        {
            visited.insert(n);
            n=next(n);
        }
        return (n==1);
    }
};