class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& land,int i,int j, int& x, int& y,int sum){
        land[i][j]=0;
        if((i+j)>sum){
            x=i;
            y=j;
            sum=(i+j);
        }
        for(auto [dx,dy]:dir){
            int nx=i+dx,ny=j+dy;
            if(nx>=0 && ny>=0 && nx<land.size() && ny<land[0].size() && land[nx][ny]==1) dfs(land,nx,ny,x,y,sum);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n=land.size(),m=land[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    vector<int> sub;
                    sub.push_back(i);
                    sub.push_back(j);
                    int x=0,y=0;
                    dfs(land,i,j,x,y,0);
                    sub.push_back(x);
                    sub.push_back(y);
                    ans.push_back(sub);
                }
            }
        }
        return ans;
    }
};