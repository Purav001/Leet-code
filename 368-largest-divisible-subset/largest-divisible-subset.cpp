class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        //imp to sort
        sort(nums.begin(),nums.end());
        // sort because this time we need subset not subsequence, hence the order does not matter and we use an intution that in [a,b,c] if b is divisible by a and ci divisible by b , there foe c is autimatically divisible by a
        // therefor we can ,ake this problem to be longest divisible subsequence problem


        // tabulation

        // dp for two changing variable , current index and prev index for comaprision;
        // vector<vector<int>> dp(n+1,vector<int>(n+2,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--){
        //         int len=dp[i+1][j+1];
        //         if(j==-1 || nums[i]%nums[j]==0 || nums[j]%nums[i]==0) len=max(len,1+dp[i+1][i+1]);
        //         dp[i][j+1]=len;
        //     }
        // }

        // space optimised 
        
        vector<int> dp(n+1,1),hash(n,1);
        // dp for only current index , dp[i] states the largest divisible subset till index i
        int maxi=0,last=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0) && 1+dp[j]>dp[i] ){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};