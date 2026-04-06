class Solution {
public:
    bool found(vector<int>& nums, int target,int m){
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size(),m=nums[0].size();
        for(int i=0;i<n;i++){
            if(target<nums[i][0]) return false;
            if(target<=nums[i][m-1]) return found(nums[i],target,m);
        }
        return false;
    }
};