class Solution {
public:
    // basically we want to check that can we form s3 with subsequences of s1 and s2
    // so we take three changing variables ,i,j,k which represent the index of 3 strings
    // we compare that weather the i is valid and if it is eqaul to that of s3[k] than explore the possibilites 
    // and same for j
    
    // vector<vector<int>> dp;
    // bool solve(string s1, string s2, string s3,int i,int j,int k){
    //     if(k==s3.length()) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     bool ans=false;
    //     if(i<s1.length() && s1[i]==s3[k]) ans|=solve(s1,s2,s3,i+1,j,k+1);
    //     if(j<s2.length() && s2[j]==s3[k]) ans|=solve(s1,s2,s3,i,j+1,k+1);
    //     return dp[i][j]=ans;
    // }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length(),l=s3.length();
        if(n+m!=l) return false;
        // memoisation
        
        // dp.resize(n+1,vector<int>(m+1,-1));
        // return solve(s1,s2,s3,0,0,0);

        // tabulation

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[n][m]=true;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                int k=i+j;
                if(i<n && s1[i]==s3[k]) dp[i][j]= dp[i][j] || dp[i+1][j];
                if(j<m && s2[j]==s3[k]) dp[i][j]= dp[i][j] || dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};