class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(vector<int>& coins,int n,int target){
    //     if(target==0) return 1;
    //     if(n<0) return 0;
    //     if(dp[n][target]!=-1) return dp[n][target];
    //     int nt=solve(coins,n-1,target);
    //     int t= (target>=coins[n])? solve(coins,n,target-coins[n]):0; // solve(coins,n,target-coins[n]) because we can take a coin infinite number of times;
    //     return dp[n][target]=nt+t;
    // }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount<0) return 0;
        // dp.resize(n,vector<int>(amount+1,-1));
        // return solve(coins,n-1,amount);
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,0));
        vector<unsigned long long> curr(amount+1,0),prev(amount+1,0);
        for(int i=0;i<=amount;i++) prev[i]= (i%coins[0]==0);
        for(int i=1;i<n;i++){
            for(int k=0;k<=amount;k++){
                unsigned long long nt=prev[k];
                unsigned long long t= 0;
                if (k>=coins[i]) t=curr[k-coins[i]];
                curr[k]=(nt+t);
            }
            prev=curr;
        }
        return prev[amount];
    }
};