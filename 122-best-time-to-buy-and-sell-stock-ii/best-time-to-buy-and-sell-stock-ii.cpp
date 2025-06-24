class Solution {
public:
    // on every day we have two options to buy or not buy 
    // if we buy on a day , further we will have two options to sell or not sell
    
    // there are two changing params - n and buy 
    // for n there are prices.size() number of ways  but for buy there are only two ways 
    
    // vector<vector<long long>> dp;
    // int solve(vector<int>& prices,int n,int buy){
    //     if(n==prices.size()) return 0;
    //     if(dp[n][buy]!=-1) return dp[n][buy];
    //     long long profit=0;
    //     if(buy) profit= max((-prices[n]+solve(prices,n+1,0)),solve(prices,n+1,1));
    //     else profit=max((prices[n]+solve(prices,n+1,1)),solve(prices,n+1,0));
    //     return dp[n][buy]=profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // memoisation

        // dp.resize(n,vector<long long>(2,-1));
        // return solve(prices,0,1);
        
        // tabulation

        // vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        // dp[n][0]=dp[n][1]=0;

        // space optimisation

        vector<long long> prev(2,0),cur(2,0);
        prev[0]=prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                long long profit=0;
                if(j) profit=max((-prices[i]+prev[0]),prev[1]);
                else profit=max((prices[i]+prev[1]),prev[0]);
                cur[j]=profit;
            }
            prev=cur;
        }
        return prev[1];
    }
};