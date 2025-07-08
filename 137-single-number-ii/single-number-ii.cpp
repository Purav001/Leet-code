class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int bit=0;
            for(int num:nums){
                if(num &(1<<i)) bit++;
            }
            if(bit%3!=0){
                ans |=(1<<i);
            }
        }
        return ans;
    }
};