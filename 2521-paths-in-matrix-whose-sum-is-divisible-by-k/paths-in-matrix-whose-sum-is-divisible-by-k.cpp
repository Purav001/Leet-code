class Solution {
public:
    const int MOD= 1e9+7;
    int m,n;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int k,int m, int n,int rem){
        if(m<0 || n<0) return 0;
        rem= (rem+grid[m][n])%k;
        if(m==0 && n==0) return rem==0?1:0;
        if(dp[m][n][rem]!=-1) return dp[m][n][rem];

        int up=solve(grid,k,m-1,n,rem);
        int left=solve(grid,k,m,n-1,rem);
        return dp[m][n][rem]=(up+left)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        // memoisation

        // dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
        // return solve(grid,k,m-1,n-1,0);

        // tabulation

        // dp.resize(m,vector<vector<int>>(n,vector<int>(k,0)));
        // dp[0][0][grid[0][0]%k]=1;

        // space optimisation

        vector<vector<int>> prev(n,vector<int>(k,0)),cur(n,vector<int>(k,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    cur[0][grid[i][j]%k]=1;
                    continue;
                }
                for(int rem=0;rem<k;rem++){
                    int nm=(rem+grid[i][j])%k;
                    if(i>0) cur[j][nm]=(cur[j][nm]+prev[j][rem])%MOD;
                    if(j>0) cur[j][nm]=(cur[j][nm]+cur[j-1][rem])%MOD;
                }
            }
            prev=cur;
            cur.assign(n,vector<int>(k,0));
        }
        return prev[n-1][0];
    }
};