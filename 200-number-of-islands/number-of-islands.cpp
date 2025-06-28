class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(int i,int j, vector<vector<char>>& grid){
        grid[i][j]='0';
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]=='1'){
                    grid[nx][ny]='0';
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                        cnt++;
                        bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};