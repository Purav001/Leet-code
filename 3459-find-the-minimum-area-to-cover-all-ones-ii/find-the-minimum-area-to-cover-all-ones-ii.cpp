class Solution {
public:
    // basically we need to divide the grid into three parts
    // we can do it by havung two splits in the grid

    // for this we have 3 cases for row splits
    // case 1:
    // we do a top row split and bottom col split

    // case 2:
    // we do bottom row split and top col split

    // case 3:
    // we do only row splits

    // we repeat these splits again , but now col splits - by rotating the array
    
    // so total 6 cases

    // after getting the splits , now we need to find the area of smallest rectangle that covers all the one in one split

    int solve(int r1,int r2,int c1,int c2,vector<vector<int>>& grid) {
        // gives the minimum area rectangle in each splited grid
        int m=grid.size(),n=grid[0].size();
        int rmax=-1,rmin=m,cmax=-1,cmin=n;
        for(int i=r1;i<r2;i++){
            for(int j=c1;j<c2;j++){
                if(grid[i][j]==1){
                    rmin=min(rmin,i);
                    rmax=max(rmax,i);
                    cmin=min(cmin,j);
                    cmax=max(cmax,j);
                }
            }
        }
        if (rmax == -1) return 0;
        return (cmax-cmin+1)*(rmax-rmin+1);
    }

    int split(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=INT_MAX;

        // case 1
        for(int i=1;i<m;i++){ // i - rowSplit
            for(int j=1;j<n;j++){ // j- colSplit
                int top= solve(0,i,0,n,grid);
                int bl=solve(i,m,0,j,grid); // bl- bottom left
                int br=solve(i,m,j,n,grid); // br-bottom right

                ans=min(ans,top+bl+br);
            }
        }
        // case 2
        for(int i=1;i<m;i++){ // i - rowSplit
            for(int j=1;j<n;j++){ // j- colSplit
                int bottom= solve(i,m,0,n,grid);
                int tl=solve(0,i,0,j,grid); // bl- bottom left
                int tr=solve(0,i,j,n,grid); // br-bottom right

                ans=min(ans,bottom+tl+tr);
            }
        }
        // case 3 - only row split
        for(int i=1;i<m;i++){
            for(int j=i+1;j<m;j++){
                int top=solve(0,i,0,n,grid);
                int middle=solve(i,j,0,n,grid);
                int bottom=solve(j,m,0,n,grid);

                ans=min(ans,top+middle+bottom);
            }
        }
        return ans;
    }
    // rotate the matrix cloackwise - and then perform the splits on it
    vector<vector<int>> rotate(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> rotated(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rotated[j][m-i-1]=grid[i][j];
            }
        }
        return rotated;
    }
    int minimumSum(vector<vector<int>>& grid){
        int ans=split(grid);
        vector<vector<int>> rotated=rotate(grid);
        ans=min(ans,split(rotated));
        return ans;
    }
};