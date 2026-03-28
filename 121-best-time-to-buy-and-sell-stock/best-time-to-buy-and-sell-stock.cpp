class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0],profit=-1;
        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-buy);
            if(prices[i]<buy) buy=prices[i];
        }
        return (profit<=0?0:profit);
    }
};