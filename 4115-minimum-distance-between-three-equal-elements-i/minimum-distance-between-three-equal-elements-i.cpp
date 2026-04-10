class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        bool found=false;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()>=3) found=true;
        }
        if(!found) return -1;
        int ans=INT_MAX;
        for(auto i:mp){
            if(i.second.size()>=3){
                for(int j=0;j<i.second.size()-2;j++){
                    ans=min(ans,2*(i.second[j+2]-i.second[j]));
                }
            }
        }
        return ans;
    }
};