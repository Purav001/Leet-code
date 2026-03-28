class Solution {
public:
    // 90degree is row wise reverse of tranpose matrix
    void rotate(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                swap(nums[i][j],nums[j][i]);
            }
        }
        for(int i=0;i<m;i++) reverse(nums[i].begin(),nums[i].end());
    }
};