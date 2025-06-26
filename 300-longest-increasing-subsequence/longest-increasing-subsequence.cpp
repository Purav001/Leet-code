class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(vector<int>& nums,int n, int m){
    //     if(n==nums.size()) return 0;
    //     if(dp[n][m+1]!=-1) return dp[n][m+1];
    //     int len= solve(nums,n+1,m);
    //     if(m==-1 || nums[n]>nums[m]) len= max(len,(1+solve(nums,n+1,n)));
    //     return dp[n][m+1]=len;
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // memoisation

        // dp.resize(n,vector<int>(n+1,-1));
        // return solve(nums,0,-1);

        // tabulation

        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        //space optimisation

        // vector<int> prev(n+1,0),cur(n+1,0);
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--){
        //         int len=prev[j+1];
        //         if(j==-1 || nums[i]>nums[j]) len= max(len,(1+prev[i+1]));
        //         cur[j+1]=len;
        //     }
        //     prev=cur;
        // }
        // return prev[0];

        // more optimised version

        vector<int> dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max((1+dp[j]),dp[i]);
                }
            }
            maxi= max(maxi,dp[i]);
        }
        return maxi;
    }
};