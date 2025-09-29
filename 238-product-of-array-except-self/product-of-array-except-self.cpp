class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pif0=0,p=1;
        int cnt=0;
        for(int i:nums){
            if(i==0){
                pif0=1;
                cnt++;
            }
            else p=1ll*p*i;
        }
        if(cnt==nums.size()) p=0;
        vector<int> ans;
        for(int i:nums){
            if(pif0){
                if(i==0 && cnt==1) ans.push_back(p);
                else ans.push_back(0);
            }
            else ans.push_back(p/i);
        }
        return ans;
    }
};