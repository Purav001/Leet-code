class Solution {
public:
    // we have to divide the array into two subsets with equal sum , i.e the sum will be half the total sum
    //if the total sum comes out to be odd , than the array is not partionable

    // vector<vector<int>> dp;
    // bool solve(vector<int>& nums,int n,int target){
    //     if(target==0) return true;
    //     if(n==0) return nums[n]==target;
    //     if(dp[n][target]!=-1) return dp[n][target];
    //     bool nt= solve(nums,n-1,target);
    //     bool t=false;
    //     if(target>=nums[n]) t=solve(nums,n-1,target-nums[n]);
    //     return dp[n][target]= t||nt;
    // }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum%2!=0) return false;
        int target=sum/2;
        // dp.resize(n,vector<int>(target+1,-1));
        // return solve(nums,n-1,target);
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool nt=dp[i-1][j];
                bool t=false;
                if(j>=nums[i]) t=dp[i-1][j-nums[i]];
                dp[i][j]=nt||t;
            }
        }
        return dp[n-1][target];
    }
};