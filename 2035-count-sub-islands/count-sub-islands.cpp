class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid2,int i,int j){
        grid2[i][j]=0;
        for(auto [dx,dy]:dir){
            int nx=i+dx,ny=j+dy;
            if(nx>=0 && ny>=0 && nx<grid2.size() && ny<grid2[0].size() && grid2[nx][ny]==1 ) dfs(grid2,nx,ny);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid1[i][j]==0) dfs(grid2,i,j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    cnt++;
                    dfs(grid2,i,j);
                }
            }
        }
        return cnt;
    }
};