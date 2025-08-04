class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int> m;
        int l=0,r=0,maxlen=0;
        while(r<nums.size()){
            m[nums[r]]++;
            while(m.size()>2){
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};