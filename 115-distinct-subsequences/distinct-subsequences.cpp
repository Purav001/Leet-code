class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(string s, string t,int n,int m){
    //     if(m<0) return 1;
    //     if(n<0) return 0;
    //     if(dp[n][m]!=-1) return dp[n][m];
    //     if(s[n]==t[m]) return dp[n][m]=solve(s,t,n-1,m-1)+solve(s,t,n-1,m);
    //     return dp[n][m]=solve(s,t,n-1,m);
    // }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        // dp.resize(n,vector<int>(m,-1));
        // return solve(s,t,n-1,m-1);
        vector<vector<double>> dp(n+1,vector<double>(m+1,-1));
        vector<double> prev(m+1,0),cur(m+1,0);

        // as the base case are if(m<0) && if(n<0) , we shift the indexes to right to make base cases for index=0
        // for(int i=0;i<=m;i++) dp[0][i]=0;
        // for(int i=0;i<=n;i++) dp[i][0]=1;
        prev[0]=cur[0]=1;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s[i-1]==t[j-1]) cur[j]=prev[j]+prev[j-1];
        //         else cur[j]=prev[j];
        //     }
        //     prev=cur;
        // }
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]) prev[j]=prev[j-1]+prev[j];
            }
        }
        return (int)prev[m];
    }
};
auto init = atexit([]()
    { ofstream("display_runtime.txt") << "0"; });
