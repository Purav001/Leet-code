class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
         // consisder each roaw as histogram and its height as pillars of histogram
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1) matrix[i][j]+=matrix[i-1][j];  // calculate height of histogram
            }
        }
        for(int i=0;i<n;i++){
            // sort these pillars to get iterate from the shortest pillar and get the max area
            sort(matrix[i].begin(),matrix[i].end());
            for(int j=0;j<m;j++) ans=max(ans,matrix[i][j]*(m-j));
        }
        return ans;
    }
};