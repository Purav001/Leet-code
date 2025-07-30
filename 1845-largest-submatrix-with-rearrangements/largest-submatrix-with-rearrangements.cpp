class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> hist(m,0);
        int ans=0;
        // consisder each roaw as histogram and its height as pillars of histogram
        for(int i=0;i<n;i++){
            // calculate height of histogram
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) hist[j]=0;
                else hist[j]+=1;
            }
            // sort these pillars
            vector<int> row=hist;
            sort(row.begin(),row.end());
            // find the max area
            for(int j=0;j<m;j++) ans=max(ans,row[j]*(m-j));
        }
        return ans;
    }
};