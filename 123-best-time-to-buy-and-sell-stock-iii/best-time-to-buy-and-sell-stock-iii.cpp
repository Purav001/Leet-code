class Solution {
public:
    // vector<vector<vector<int>>> dp;
    // int solve(vector<int>& prices,int n,int buy,int t){
    //     if(n==prices.size() || t==0) return 0;
    //     if(dp[n][buy][t]!=-1) return dp[n][buy][t];
    //     long long profit=0;
    //     if(buy) profit= max((-prices[n]+solve(prices,n+1,0,t)),solve(prices,n+1,1,t));
    //     else profit=max((prices[n]+solve(prices,n+1,1,t-1)),solve(prices,n+1,0,t));
    //     return dp[n][buy][t]=profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // memoisation

        // dp.resize(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(prices,0,1,2);

        // tabulation

        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // no need for these base cases , as we have already initialised the dp array with 0

        // for(int i=0;i<3;i++){
        //     dp[n][0][i]=0;
        //     dp[n][1][i]=0;
        // }
        // for(int i=0;i<=n;i++){
        //     dp[i][0][0]=0;
        //     dp[i][1][0]=0;
        // }

        // space optimisation
        vector<vector<int>> prev(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int l=1;l<=2;l++){
                    long long profit=0;
                    if(j) profit= max((-prices[i]+prev[0][l]),prev[1][l]);
                    else profit= max((prices[i]+prev[1][l-1]),prev[0][l]);
                    cur[j][l]=profit;
                }
                prev=cur;
            }
        }
        return prev[1][2];
    }
};