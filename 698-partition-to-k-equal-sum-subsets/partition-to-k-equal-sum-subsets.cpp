class Solution {
public:
    // DP + BitMask
    // basically we need to divide into k subsets ,so we need to check for all subsets whether target is achievable or not

    // A bitmask used -> which elements are already included.
	// The current running sum curSum of the subset being formed.
	// The number of subsets left to form (k).

    // When curSum == target, we recursively start a new subset.

    // dp[mask] = means the sum achieved by using the subset represented by mask

    unordered_map<int,bool> dp;
    bool solve(vector<int>& nums, int k, int mask, int csum, int cnt, int target){
        int n=nums.size();
        if(cnt==k-1) return true;
        if(dp.count(mask)) return dp[mask];
        if(csum==target) return dp[mask]=solve(nums,k,mask,0,cnt+1,target);
        for(int i=0;i<n;i++){
            if((mask>>i)&1) continue; // already used bit
            if(csum+nums[i]>target) continue;
            if(solve(nums,k, mask|(1<<i) ,csum+nums[i],cnt,target)) return dp[mask]=true;
        }
        return dp[mask]=false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(nums.size()<k || sum%k!=0) return false;
        int target=sum/k;
        sort(nums.rbegin(),nums.rend());
        if(nums[0]>target) return false; // these element cannot be partioned into any subset
        return solve(nums,k,0,0,0,target);
    }
};