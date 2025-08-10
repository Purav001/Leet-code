class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long solve(vector<int>& prices,int n,int holding,int k){
        if(n==prices.size() || k==0){
            if(holding==0) return 0;
            else return LLONG_MIN/4;
        }
        if(dp[n][holding][k]!=-1) return dp[n][holding][k];
        long long profit=0;
        if(holding==0){
            profit=max({
                -prices[n]+solve(prices,n+1,1,k),
                prices[n]+solve(prices,n+1,2,k),
                solve(prices,n+1,0,k)
            });
        }
        else if(holding==1){
            profit=max({
                prices[n]+solve(prices,n+1,0,k-1),
                solve(prices,n+1,1,k)
            });
        }
        else{
            profit=max({
                -prices[n]+solve(prices,n+1,0,k-1),
                solve(prices,n+1,2,k)
            });
        }
        return dp[n][holding][k]=profit;
        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        dp.resize(n,vector<vector<long long>>(3,vector<long long>(k+1,-1)));
        return solve(prices,0,0,k);
    }
};