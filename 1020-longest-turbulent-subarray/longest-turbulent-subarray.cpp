class Solution {
public:
    int evenGreater(vector<int>& nums){
        int n=nums.size();
        int len=0;
        int l=0,r=0;
        while(r<n-1){
            if(r%2==0){
                if(nums[r]<nums[r+1]) r++;
                else {
                    len=max(len,r-l+1);
                    l=(++r);
                }
            }
            else{
                if(nums[r]>nums[r+1]) r++;
                else {
                    len=max(len,r-l+1);
                    l=(++r);
                }
            }
        }
        len =max(len,r-l+1);
        return len;
    }
    int oddGreater(vector<int>& nums){
        int n=nums.size();
        int len=0;
        int l=0,r=0;
        while(r<n-1){
            if(r%2==0){
                if(nums[r]>nums[r+1]) r++;
                else {
                    len=max(len,r-l+1);
                    l=(++r);
                }
            }
            else{
                if(nums[r]<nums[r+1]) r++;
                else {
                    len=max(len,r-l+1);
                    l=(++r);
                }
            }
        }
        len = max(len,r-l+1);
        return len;
    }
    int maxTurbulenceSize(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        return max(evenGreater(nums),oddGreater(nums));
    }
};