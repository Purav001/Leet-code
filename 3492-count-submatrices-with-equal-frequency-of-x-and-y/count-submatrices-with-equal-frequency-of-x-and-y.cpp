class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>> dp(m); // array to store (hasX, difference of 'X' and 'Y')
        int ans=0;
        for(int i=0;i<n;i++){
            int sum=0,fl=0; // fl- flag set when atleast one x has been encountered
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    fl=1;
                    sum++;
                }
                else if(grid[i][j]=='Y') sum--;
                dp[j].first|=fl;
                dp[j].second+=sum;
                if(dp[j].first && dp[j].second==0) ans++; // if both the condition satisfy , then the submatrix is valid
            }
        }
        return ans;
    }
};