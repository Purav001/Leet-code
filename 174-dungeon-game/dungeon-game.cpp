class Solution {
public:
    // basically we need minimum energy that a knight has to save the princess
    // we need to handle base case senstively 
    // basically we are calculating the min energy the knight shoul have before entering a cell
    // like to enter the cell [m-1,n-1] if the dungeon[i][j]>0 , the knight can have min 1 energy before the cell
    // and if dungeon[i][j]<0 the knight must have 1+abs(dungeon[i][j]) of energy to prevent dieing
    // so basically dp[i][j] tells us the min amount of energy the knight must to have to enter cell [i,j]
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& dungeon,int i,int j,int m,int n){
        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j==n-1) return max(1,1-dungeon[i][j]);
        if(dp[i][j]!=-1) return dp[i][j];
        int need=min(solve(dungeon,i+1,j,m,n),solve(dungeon,i,j+1,m,n))-dungeon[i][j];
        return dp[i][j]=max(need,1);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        // memoisation

        // dp.resize(m,vector<int>(n,-1));
        // return solve(dungeon,0,0,m,n);

        // tabulation

        dp.resize(m,vector<int>(n,1e9));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) dp[i][j]=max(1,1-dungeon[i][j]);
                else{
                    int d=INT_MAX,r=INT_MAX;
                    if(i<m-1) d=dp[i+1][j];
                    if(j<n-1) r=dp[i][j+1];
                    int need=min(d,r)-dungeon[i][j];
                    dp[i][j]=max(1,need);
                }
            }
        }
        return dp[0][0];
    }
};