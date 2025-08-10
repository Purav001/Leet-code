class Solution {
public:
    // memoisation

    // holding states
    // 0- we can either buy, short sell, os skip to next day
    // 1- we have bought the stock , now we need to sell to complete the transaction
    // 2- we have short sell the stock , mow we need to buy the stock

    // vector<vector<vector<long long>>> dp;
    // long long solve(vector<int>& prices,int n,int holding,int k){
    //     if(n==prices.size() || k==0){
    //         if(holding==0) return 0;
    //         else return LLONG_MIN/4;
    //     }
    //     if(dp[n][holding][k]!=-1) return dp[n][holding][k];
    //     long long profit=0;
    //     if(holding==0){
    //         profit=max({
    //             -prices[n]+solve(prices,n+1,1,k),
    //             prices[n]+solve(prices,n+1,2,k),
    //             solve(prices,n+1,0,k)
    //         });
    //     }
    //     else if(holding==1){
    //         profit=max({
    //             prices[n]+solve(prices,n+1,0,k-1),
    //             solve(prices,n+1,1,k)
    //         });
    //     }
    //     else{
    //         profit=max({
    //             -prices[n]+solve(prices,n+1,0,k-1),
    //             solve(prices,n+1,2,k)
    //         });
    //     }
    //     return dp[n][holding][k]=profit;
        
    // }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        // memoisation

        // dp.resize(n,vector<vector<long long>>(3,vector<long long>(k+1,-1)));
        // return solve(prices,0,0,k);

        // tabulation

        // vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(3,vector<long long>(k+1,0)));
        // for(int i=0;i<=k;i++){
        //     dp[n][0][i]=0;
        //     dp[n][1][i]=-1e14;
        //     dp[n][2][i]=-1e14;
        // }
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=2;j++){
        //         for(int l=0;l<=k;l++){
        //             long long nt=dp[i+1][j][l]; // nt - not take
        //             long long t=-1e14; // t- take
        //             if(l>0){
        //                 if(j==0) t=max(-prices[i]+dp[i+1][1][l],prices[i]+dp[i+1][2][l]); // either long buy or short sell
        //                 else if(j==1) t=prices[i]+dp[i+1][0][l-1]; // long buy
        //                 else t=-prices[i]+dp[i+1][0][l-1]; // short sell
        //             }
        //             dp[i][j][l]=max(t,nt);
        //         }
        //     }
        // }
        // return dp[0][0][k];

        // space optimisation

        vector<vector<long long>> next(3,vector<long long>(k+1,0)),curr(3,vector<long long>(k+1,0));
        for(int i=0;i<=k;i++){
            next[0][i]=0;
            next[1][i]=-1e14;
            next[2][i]=-1e14;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=2;j++){
                for(int l=0;l<=k;l++){
                    long long nt=next[j][l]; // nt - not take
                    long long t=-1e14; // t- take
                    if(l>0){
                        if(j==0) t=max(-prices[i]+next[1][l],prices[i]+next[2][l]); // either long buy or short sell
                        else if(j==1) t=prices[i]+next[0][l-1]; // long buy
                        else t=-prices[i]+next[0][l-1]; // short sell
                    }
                    curr[j][l]=max(t,nt);
                }
            }
            next=curr;
        }
        return next[0][k];
    }
};