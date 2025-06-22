class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums,int n,int target){
        if(n==0){
            if(target==0 && nums[0]==0) return 2; // +0 and -0
            if(target==0 || target==nums[n]) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int nt=solve(nums,n-1,target);
        int t = (target>=nums[n])? solve(nums,n-1,target-nums[n]):0;
        return dp[n][target]=nt+t;
    }
    int findTargetSumWays(vector<int>& nums, int dif) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum<dif || (sum-dif)%2) return 0;
        int target=(sum-dif)/2;
        dp.resize(n,vector<int>(target+1,-1));
        return solve(nums,n-1,target);
    }
};