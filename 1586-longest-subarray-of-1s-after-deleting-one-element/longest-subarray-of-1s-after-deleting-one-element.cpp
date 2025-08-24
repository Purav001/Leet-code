class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,cnt=0;
        int ans=INT_MIN;
        while(r<n){
            if(nums[r]==0) cnt++;
            while(cnt>1){
                if(nums[l]==0) cnt--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans-1; // return after removing that one 0
    }
};