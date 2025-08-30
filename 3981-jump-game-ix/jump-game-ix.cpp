class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size(),mini=INT_MAX;
        vector<int> ans={nums[0]};
        // preffix maximum of i
        for(int i=1;i<n;i++) ans.push_back(max(nums[i],ans.back()));
        // suffix minimum of i
        for(int i=n-1;i>=0;mini=min(mini,nums[i--])) if(ans[i]>mini) ans[i]=ans[i+1];
        return ans;
    }
};