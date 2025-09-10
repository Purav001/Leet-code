class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        if(m*n != r*c) return mat;
        vector<vector<int>> ans(r,vector<int>(c));
        vector<int> store(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                store[n*i+j]=mat[i][j]; // store the lements in 1D array
            }
        }
        for(int i=0;i<m*n;i++){
            ans[i/c][i%c]=store[i]; // store back the elments in 2D array
        }
        return ans;
    }
};