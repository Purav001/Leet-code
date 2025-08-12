class Solution {
public:
    // classic knapsack problem
    // dp[n][i] tells the number of ways to get n as sum of number raised to power x with i as max element 
    // take / not take approach

    const int MOD=1e9+7;
    // memoisation

    // vector<vector<int>> dp;
    // int solve(int i,int n,int x){
    //     if(n==0) return 1;
    //     if(n<0 || n<pow(i,x)) return 0;
    //     if(dp[n][i]!=-1) return dp[n][i];
    //     int t=solve(i+1,n-pow(i,x),x); // t- take
    //     int nt=solve(i+1,n,x); // nt- not take
    //     return dp[n][i]=(t+nt)%MOD;
    // }

    int numberOfWays(int n, int x) {
        // max number can be the number itself if x=1 , so we take (n+1)*(n+1) matrix;
        // memoisation

        // dp.resize(n+1,vector<int>(n+1,-1));
        // return solve(1,n,x);

        // tabulation
        vector<int> pow;
        for(int j=1; ;j++){
            long long val=1;
            for(int k=0;k<x;k++) val*=j;
            if(val>n) break;
            pow.push_back((int)val);
        }
        int m=pow.size();
        vector<vector<int>> dp(n+1,vector<int>(m+2,0));
        for(int i=0;i<=m+1;i++) dp[0][i]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                int nt= dp[i][j+1];
                int t=0;
                if(i>=pow[j-1]) t=dp[i-pow[j-1]][j+1];
                dp[i][j]=(t+nt)%MOD;
            }
        }
        return dp[n][1];
    }
};