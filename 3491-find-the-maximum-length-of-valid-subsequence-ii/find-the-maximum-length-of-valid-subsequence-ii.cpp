class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& nums,int k,int i,int p,int c,int n){
        if(i==n) return 0;
        if(dp[i][p][c]!=-1) return dp[i][p][c];
        int nt=solve(nums,k,i+1,p,c,n);
        int t=0;
        if((nums[i]+nums[p])%k==c) t=1+solve(nums,k,i+1,i,c,n);
        return dp[i][p][c]=max(t,nt);
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==2) return n;
        // int maxLen=0;
        // memoisation

        // dp.resize(n,vector<vector<int>>(n,vector<int>(k,-1)));
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         maxLen=max(maxLen,2+solve(nums,k,j+1,j,(nums[i]+nums[j])%k,n));
        //     }
        // }
        // return maxLen;

        // tabulation

        // dp.resize(n,vector<vector<int>>(n,vector<int>(k,-1)));
        // for (int i=0; i < n; i++){
        //     for (int j = i+1; j < n; j++){
        //         int mod = (nums[i]+nums[j])%k;
        //         dp[j][i][mod]=2;
        //         maxLen=max(maxLen,dp[j][i][mod]);
        //     }
        // }
        // for (int i=2; i < n; i++){
        //     for (int j=1; j < i; j++){
        //         for (int p=0; p < j; p++) {
        //             int mod = (nums[p] + nums[j]) % k;
        //             if (dp[j][p][mod] > 0 && (nums[j] + nums[i]) % k == mod) {
        //                 dp[i][j][mod] = max(dp[i][j][mod], dp[j][p][mod] + 1);
        //                 maxLen = max(maxLen, dp[i][j][mod]);
        //             }
        //         }
        //     }
        // }
        // return maxLen;

        vector<unordered_map<int, int>> dp(n); 
        int ans=0;
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
            for (int j = 0; j < i; ++j) {
                int mod = (nums[i] + nums[j]) % k;
                if (dp[j].count(mod)) {
                    dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                } else {
                    dp[i][mod] = max(dp[i][mod], 2); 
                }
                ans = max(ans, dp[i][mod]);
            }
        }
        return ans;
    }
};