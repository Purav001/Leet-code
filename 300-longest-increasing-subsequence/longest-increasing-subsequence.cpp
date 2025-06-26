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

    int lengthOfLISViaDP(vector<int>& nums) {
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

        // more optimised version + printing hte subsequence

        vector<int> dp(n,1),hash(n,0);
        int maxi=0,last=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j; // to store the prev smaller element in comparison to curr element in the longest subsequence
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i; // to store the index of last element of longest subsequence
            }
        }
        vector<int> ans(maxi);
        int ind=maxi-2;
        ans[ind+1]=nums[last];
        while(hash[last]!=last){
            last=hash[last];
            ans[ind--]=nums[last];
        }
        // ans store the longest increasing subsequence
        return maxi;
    }
    
    // using Binary search , most optimised code
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind= lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                // lower_bound(temp.begin(),temp.end(),nums[i]) is binary search 
                // which Finds the first position in temp where nums[i] can be inserted without violating the sorted order
                temp[ind]=nums[i];
            }
        }
        return len;
    }
};