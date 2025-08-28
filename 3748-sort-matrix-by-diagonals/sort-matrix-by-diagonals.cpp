class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==1 && n==1) return grid;
        map<pair<int,int>,vector<int>> mp;
        for(int i=0;i<m;i++){
            int j=0,t=i;
            while(t<m && j<n) mp[{i,0}].push_back(grid[t++][j++]);
            sort(mp[{i,0}].rbegin(),mp[{i,0}].rend());
        }
        for(int j=1;j<n;j++){
            int i=0,t=j;
            while(i<m && t<n) mp[{0,j}].push_back(grid[i++][t++]);
            sort(mp[{0,j}].begin(),mp[{0,j}].end());
        }
        for(int i=0;i<m;i++){
            int j=0,t=i;
            for(int k=0;k<mp[{i,0}].size();k++) grid[t++][j++]=mp[{i,0}][k];
        }
        for(int j=0;j<n;j++){
            int i=0,t=j;
            for(int k=0;k<mp[{0,j}].size();k++) grid[i++][t++]=mp[{0,j}][k];
        }
        return grid;
    }
};