class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<char>> ans(m,vector<char>(n));
        for(int i=0;i<n;i++){
            int empty=m-1;
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]=='*') empty=j-1;
                else if(grid[i][j]=='#'){
                    if(j!=empty) swap(grid[i][j],grid[i][empty]);
                    empty--;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) ans[j][(n-1)-i]=grid[i][j];
        }
        return ans;
    }
};