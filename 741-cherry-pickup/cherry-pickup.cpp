class Solution {
public:
    // backtracking

    // int cnt=0;
    // void solve(vector<vector<int>>& grid,int i,int j,int n,int cherries){
    //     if(i>=n || j>=n || grid[i][j]==-1) return;
    //     if(i==n-1 && j==n-1) solve1(grid,i,j,cherries);
    //     int curr=grid[i][j];
    //     grid[i][j]=0;
    //     solve(grid,i+1,j,n,cherries+curr);
    //     solve(grid,i,j+1,n,cherries+curr);
    //     grid[i][j]=curr;
    // }
    // void solve1(vector<vector<int>>& grid, int i,int j,int cherries){
    //     if(i<0 || j<0 || grid[i][j]==-1) return;
    //     if(i==0 && j==0){
    //         cnt=max(cnt,cherries);
    //         return;
    //     }
    //     int curr=grid[i][j];
    //     grid[i][j]=0;
    //     solve1(grid,i-1,j,cherries+curr);
    //     solve1(grid,i,j-1,cherries+curr);
    //     grid[i][j]=curr;
    // }

    vector<vector<vector<vector<int>>>> dp;
    int solve(vector<vector<int>>& grid,int i,int j,int x,int y,int n){
        if(i>=n || j>=n || x>=n || y>=n || grid[i][j]==-1 || grid[x][y]==-1) return -1e8;
        if(i==n-1 && j==n-1 && x==n-1 && y==n-1) return grid[i][j];
        if(dp[i][j][x][y]!=-1) return dp[i][j][x][y];
        int curr=grid[i][j];
        if(i!=x || j!=y) curr+=grid[x][y];
        return dp[i][j][x][y]=curr+max({solve(grid,i+1,j,x+1,y,n),solve(grid,i+1,j,x,y+1,n),solve(grid,i,j+1,x+1,y,n),solve(grid,i,j+1,x,y+1,n)});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1) return 0;
        // backtracking 

        // solve(grid,0,0,n,0);
        // return cnt;

        // memoisation
        dp.resize(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,solve(grid,0,0,0,0,n));
    }
};