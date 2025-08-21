class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> histogram(m,0); // create a histogram for heights of bars
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) histogram[j]=(mat[i][j]==0)?0:histogram[j]+1;
            stack<int> st; // maintain a monotonic increasing stack
            vector<int> sum(m,0);
            for(int j=0;j<m;j++){
                while(!st.empty() && histogram[st.top()]>=histogram[j]) st.pop(); // because when histogram[j] is smaller tahn orevious bars than those taller bars cannot extend further to right
                if(!st.empty()){
                    int prev=st.top();
                    sum[j]=sum[prev]+histogram[j]*(j-prev); // sum of already counted rectangles ending at prev and the new rectangle ending at j with width (j-prev)
                }
                else sum[j]=histogram[j]*(j+1); // when there is no smaller previous element and the then the rectangle extends till 0
                st.push(j);
                ans+=sum[j];
            }
        }
        return ans;
    }
};