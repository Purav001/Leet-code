class Solution {
public:
    int solve(vector<int>& nums,int n, int target){
        if(n==0){
            if(nums[0]==0 && target==0) return 2;
            if(abs(target)==nums[n]) return 1;
            return 0;
        }
        return solve(nums,n-1,target-nums[n])+solve(nums,n-1,target+nums[n]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // dp.resize(target+1,-1);
        return solve(nums,n-1,target);
    }
};