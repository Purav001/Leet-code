class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j){
        if(i==grid.size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        int el=grid[i][j];
        for(int col=0;col<grid[0].size();col++){
            ans=min(ans,el+moveCost[el][col]+solve(grid,moveCost,i+1,col));
        }
        return ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size(),n=grid[0].size();
        // memoisation

        // dp.resize(m,vector<int>(n,-1));
        // int ans=1e9;
        // for(int i=0;i<n;i++) ans=min(ans,solve(grid,moveCost,0,i));
        // return ans;

        // tabulation

        dp.resize(m,vector<int>(n,1e9));
        for(int i=0;i<n;i++) dp[m-1][i]=grid[m-1][i];
        for(int i=m-2;i>=0;--i){
            for(int j=0;j<n;j++){
                int el=grid[i][j];
                for(int col=0;col<n;col++) dp[i][j]=min(dp[i][j],el+moveCost[el][col]+dp[i+1][col]);
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};