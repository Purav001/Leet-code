class Solution {
public:
    // basically we have to partition the array in such a way that the subarray length is <=k and each element of the subarray is changed to the max element in the subarray 
    // the main objective is to get the max sum of the array

    // vector<int> dp;
    // int solve(vector<int>& nums,int i, int k){
    //     if(i==nums.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];

    //     int len=0,maxel=INT_MIN,maxSum=INT_MIN;
    //     for(int j=i;j<min((int)nums.size(),i+k);j++){
    //         len++;
    //         maxel=max(maxel,nums[j]);
    //         int sum=len*maxel+solve(nums,j+1,k);
    //         maxSum=max(maxSum,sum);
    //     }
    //     return dp[i]=maxSum;
    // }

    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        // memoisation

        // dp.resize(n,-1);
        // return solve(nums,0,k);

        // tabulation

        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int len=0,maxel=INT_MIN,maxSum=INT_MIN;
            for(int j=i;j<min((int)nums.size(),i+k);j++){
                len++;
                maxel=max(maxel,nums[j]);
                int sum=len*maxel+dp[j+1];
                maxSum=max(maxSum,sum);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};