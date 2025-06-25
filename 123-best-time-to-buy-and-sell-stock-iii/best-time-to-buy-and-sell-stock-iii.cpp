class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices,int n,int buy,int t){
        if(n==prices.size() || t==0) return 0;
        if(dp[n][buy][t]!=-1) return dp[n][buy][t];
        long long profit=0;
        if(buy) profit= max((-prices[n]+solve(prices,n+1,0,t)),solve(prices,n+1,1,t));
        else profit=max((prices[n]+solve(prices,n+1,1,t-1)),solve(prices,n+1,0,t));
        return dp[n][buy][t]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // memoisation

        dp.resize(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,2);
    }
};