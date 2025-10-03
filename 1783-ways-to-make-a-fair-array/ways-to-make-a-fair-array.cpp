class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> odd(n,0),even(n,0);
        for(int i=0;i<n;i++){
            if(i>0){
                even[i]=even[i-1];
                odd[i]=odd[i-1];
            }
            if(i%2==0) even[i]+=nums[i];
            else odd[i]+=nums[i];
        }
        int totalEven=even[n-1],totalOdd=odd[n-1];
        int ans=0;
        for(int i=0;i<n;i++){
            int leftEven= (i==0?0:even[i-1]);
            int leftOdd= (i==0?0:odd[i-1]);
            int rightEven= totalEven-even[i];
            int rightOdd= totalOdd-odd[i];

            if((leftEven+rightOdd)==(leftOdd+rightEven)) ans++;
        }
        return ans;
    }
};