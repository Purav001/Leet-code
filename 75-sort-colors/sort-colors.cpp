class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,e=nums.size()-1,ind=0;
        while(ind<=e){
            if(nums[ind]==0) swap(nums[ind++],nums[s++]);
            else if(nums[ind]==2) swap(nums[ind],nums[e--]);
            else ind++;
        }
    }
};
