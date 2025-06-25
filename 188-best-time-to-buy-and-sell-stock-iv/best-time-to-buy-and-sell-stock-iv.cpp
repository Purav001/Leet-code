class Solution {
public:
    // vector<vector<vector<int>>> dp;
    // int solve(vector<int>& prices,int n,int buy,int t,int k){
    //     if(n==prices.size() || t>k) return 0;
    //     if(dp[n][buy][t]!=-1) return dp[n][buy][t];
    //     long long profit=0;
    //     if(buy) profit= max((-prices[n]+solve(prices,n+1,0,t,k)),solve(prices,n+1,1,t,k));
    //     else profit=max((prices[n]+solve(prices,n+1,1,t+1,k)),solve(prices,n+1,0,t,k));
    //     return dp[n][buy][t]=profit;
    // }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // memoisation

        // dp.resize(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(prices,0,1,0,k);

        // tabulation
        
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        // space optimisation

        vector<vector<int>> prev(2,vector<int>(k+1,0)),cur(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int l=1;l<=k;l++){
                    long long profit=0;
                    if(j) profit= max((-prices[i]+prev[0][l]),prev[1][l]);
                    else profit= max((prices[i]+prev[1][l-1]),prev[0][l]);
                    cur[j][l]=profit;
                }
                prev=cur;
            }
        }
        return prev[1][k];
    }
};