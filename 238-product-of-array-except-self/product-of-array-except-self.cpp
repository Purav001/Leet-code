class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // long long pif0=0,p=1;
        // int cnt=0;
        // for(int i:nums){
        //     if(i==0){
        //         pif0=1;
        //         cnt++;
        //     }
        //     else p=1ll*p*i;
        // }
        // if(cnt==nums.size()) p=0;
        // vector<int> ans;
        // for(int i:nums){
        //     if(pif0){
        //         if(i==0 && cnt==1) ans.push_back(p);
        //         else ans.push_back(0);
        //     }
        //     else ans.push_back(p/i);
        // }
        // return ans;

        int n=nums.size();
        vector<int> ans(n,1);
        int suffix=1;
        for(int i=1;i<n;i++) ans[i]=ans[i-1]*nums[i-1];
        for(int i=n-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
        }
        return ans;
    }
};