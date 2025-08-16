class Solution {
public:
    // we need to find maximum k such that AND for all the pair of elements being swaped is k

    // the basic idea is- k is AND of all the misplaced numbers
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int mask=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]!=i) mask&=nums[i];
        }
        return mask==INT_MAX?0:mask;
    }
};