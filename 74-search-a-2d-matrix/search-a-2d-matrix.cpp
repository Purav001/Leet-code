class Solution {
public:

    // O(nlog(m))

    // bool found(vector<int>& nums, int target,int m){
    //     int low=0,high=m-1;
    //     while(low<=high){
    //         int mid=low+(high-low)/2;
    //         if(nums[mid]==target) return true;
    //         else if(target>nums[mid]) low=mid+1;
    //         else high=mid-1;
    //     }
    //     return false;
    // }

    // for O(log(m*n)) we need to visualize whole 2D array as a flat array of length m*n and apply binary search on it
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        // int n=nums.size(),m=nums[0].size();
        // for(int i=0;i<n;i++){
        //     if(target<nums[i][0]) return false;
        //     if(target<=nums[i][m-1]) return found(nums[i],target,m);
        // }
        // return false;

        int m=nums.size(),n=nums[0].size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/n,col=mid%n;
            if(nums[row][col]==target) return true;
            else if(target>nums[row][col]) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};