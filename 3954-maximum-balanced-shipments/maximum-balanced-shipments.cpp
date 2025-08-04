class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int i=0;
        while(i<n){
            int mw=nums[i];
            int j=i+1;
            while(j<n){
                mw=max(mw,nums[j]);
                if(nums[j]<mw){
                    i=j+1;
                    cnt++;
                    break;
                }
                j++;
            }
            if(j==n) break;
        }
        return cnt;
    }
};