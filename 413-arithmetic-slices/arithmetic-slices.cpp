class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0,cnt=1;
        int prev=nums[1]-nums[0];
        for(int i=2;i<n;i++){
            if(cnt>1) ans+=cnt-1;
            int s=nums[i]-nums[i-1];
            if(s==prev) cnt++;
            else{
                cnt=1;
                prev=s;
            }
        }
        if(cnt>1) ans+=cnt-1;
        return ans;
    }
};