class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int sum=0,len=1e9;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                len=min(len,r-l+1);
                sum-=nums[l++];
            }
            r++;
        }
        return len!=1e9?len:0;
    }
};