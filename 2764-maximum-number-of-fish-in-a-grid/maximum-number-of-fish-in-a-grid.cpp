class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid,int i,int j,int& cnt,int m,int n){
        cnt+=grid[i][j];
        grid[i][j]=0;
        for(auto [x,y]:dir){
            int nx=i+x,ny=j+y;
            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!=0) dfs(grid,nx,ny,cnt,m,n);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    int cnt=0;
                    dfs(grid,i,j,cnt,m,n);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};