class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j){
    //     if(i==grid.size()-1) return grid[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=1e9;
    //     int el=grid[i][j];
    //     for(int col=0;col<grid[0].size();col++){
    //         ans=min(ans,el+moveCost[el][col]+solve(grid,moveCost,i+1,col));
    //     }
    //     return dp[i][j]=ans;
    // }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size(),n=grid[0].size();
        // memoisation

        // dp.resize(m,vector<int>(n,-1));
        // int ans=1e9;
        // for(int i=0;i<n;i++) ans=min(ans,solve(grid,moveCost,0,i));
        // return ans;

        // tabulation

        // dp.resize(m,vector<int>(n,1e9));

        // space optimisation

        vector<int> prev(n,1e9);
        for(int i=0;i<n;i++) prev[i]=grid[m-1][i];
        for(int i=m-2;i>=0;--i){
            vector<int> curr(n,1e9);
            for(int j=0;j<n;j++){
                int el=grid[i][j];
                for(int col=0;col<n;col++) curr[j]=min(curr[j],el+moveCost[el][col]+prev[col]);
            }
            prev=curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};