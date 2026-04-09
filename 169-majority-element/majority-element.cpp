class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,el=0;
        for(int i:nums){
            if(cnt==0){
                cnt++;
                el=i;
            }
            else if(el==i) cnt++;
            else cnt--;
        }
        cnt=0;
        for(int i:nums){
            if(i==el) cnt++;
        }
        return cnt>n/2?el:-1;
    }
};