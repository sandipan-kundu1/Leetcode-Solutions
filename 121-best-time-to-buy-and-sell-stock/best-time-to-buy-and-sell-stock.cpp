class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,mini=prices[0],currprofit;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>=mini){
                currprofit=prices[i]-mini;
                maxprofit=max(maxprofit,currprofit);
            }
            else
            mini=prices[i];
        }
        return maxprofit;
    }
};