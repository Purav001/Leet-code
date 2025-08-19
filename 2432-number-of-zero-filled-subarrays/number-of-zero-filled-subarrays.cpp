class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0;
        int n=nums.size();
        int l=0,r=0;
        while(r<n){
            if(nums[r]!=0) l=++r;
            else cnt+=(r++)-l+1;
        }
        return cnt;
    }
};