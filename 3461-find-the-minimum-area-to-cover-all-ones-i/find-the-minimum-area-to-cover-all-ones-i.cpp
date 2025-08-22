class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int rmax=INT_MIN,rmin=INT_MAX,cmax=INT_MIN,cmin=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rmin=min(rmin,i);
                    rmax=max(rmax,i);
                    cmin=min(cmin,j);
                    cmax=max(cmax,j);
                }
            }
        }
        return (cmax-cmin+1)*(rmax-rmin+1);
    }
};