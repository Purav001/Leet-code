class Solution {
public:
    // on every day we have two options to buy or not buy 
    // if we buy on a day , further we will have two options to sell or not sell
    
    // there are two changing params - n and buy 
    // for n there are prices.size() number of ways  but for buy there are only two ways 
    
    vector<vector<long long>> dp;
    int solve(vector<int>& prices,int n,int buy){
        if(n==prices.size()) return 0;
        if(dp[n][buy]!=-1) return dp[n][buy];
        long long profit=0;
        if(buy) profit= max((-prices[n]+solve(prices,n+1,0)),solve(prices,n+1,1));
        else profit=max((prices[n]+solve(prices,n+1,1)),solve(prices,n+1,0));
        return dp[n][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector<long long>(2,-1));
        return solve(prices,0,1);
    }
};