class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& coins,int i,int j,int k,int n,int m){
        if(i>=n || j>=m ) return -1e9;
        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];

        int val=coins[i][j];
        if(i==n-1 && j==m-1){
            if(val>=0) return dp[i][j][k]=val;
            // negative val
            int neutralize=(k>0?0:-1e9);
            return max(val,neutralize);
        }
        int ans=-1e9;
        if(val>=0){
            ans=val+max(solve(coins,i+1,j,k,n,m),solve(coins,i,j+1,k,n,m));
        }
        else{
            // dont neutralize
            int option1=val+max(solve(coins,i+1,j,k,n,m),solve(coins,i,j+1,k,n,m));
            // neutralize
            int option2=-1e9;
            if(k>0){
                option2=max(solve(coins,i+1,j,k-1,n,m),solve(coins,i,j+1,k-1,n,m));
            }
            ans=max(option1,option2);
        }
        return dp[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(),m=coins[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return solve(coins,0,0,2,n,m);
    }
};