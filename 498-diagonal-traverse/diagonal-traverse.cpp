class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> store(m+n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=i+j;
                if(sum%2==0) store[sum].insert(store[sum].begin(),mat[i][j]);
                else store[sum].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(auto dig:store) ans.insert(ans.end(),dig.begin(),dig.end());
        return ans;
    }
};