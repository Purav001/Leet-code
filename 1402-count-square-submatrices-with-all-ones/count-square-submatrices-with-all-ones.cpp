class Solution {
public:
    // in square problems make a DP array of same size as of the square
    // basically DP[i][j] tells that how many squares end at (i,j) i.e they have right bottom at (i,j)

    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        for(int i=0;i<n;i++) dp[i][0]=matrix[i][0];

        // if we get a one , we look for min element int the square where it is the bottom right corner
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) dp[i][j]=0;
                else dp[i][j]= min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
            }
        }

        int sum=0;
        for(auto row:dp) for(int col:row) sum+=col;
        return sum;
    }
};