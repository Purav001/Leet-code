class Solution {
public:
    int maxValue(vector<int>&nums){
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    double totalHours(vector<int>&nums , int hourly){
        double hours = 0;
        for(int i=0;i< nums.size();i++){
            hours+= ceil((double)(nums[i])/(double)(hourly));
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        std::ios::sync_with_stdio(0);
        int low =1,high = maxValue(nums),mid;
        while(low<=high){
            mid = low+(high-low)/2;
            double hours = totalHours(nums,mid);
            if(hours <=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};