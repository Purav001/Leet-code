class Solution {
public:
    int cells=0,res=0;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid, int sx, int sy,int cnt){
        if(sx<0 || sy<0 || sx>=grid.size() || sy>=grid[0].size() || grid[sx][sy]==-1) return;
        if(grid[sx][sy]==2){
            if(cnt==cells) res++;
            return;
        }
        int temp=grid[sx][sy];
        grid[sx][sy]=-1;
        for(auto [x,y]:dir) dfs(grid,sx+x,sy+y,cnt+1);
        grid[sx][sy]=temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int sx,sy;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=-1) cells++;
                if(grid[i][j]==1){
                    sx=i;sy=j;
                }
            }
        }
        dfs(grid,sx,sy,1);
        return res;
    }
};