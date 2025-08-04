class Solution {
public:
    // nums = [4, 3, 5, 1, 2]

    //     \U0001f9ed Iteration 1:
    // 	•	i = 1, nums[i] = 3, mw = 4
    // 	•	Check: mw > nums[i] → 4 > 3 → ✅
    // 	•	cnt++ → cnt = 1
    // 	•	i++ → i = 2
    // 	•	mw = nums[2] = 5

    // \U0001f9ed Iteration 2:
    // 	•	i = 3, nums[i] = 1, mw = 5
    // 	•	Check: 5 > 1 → ✅
    // 	•	cnt++ → cnt = 2
    // 	•	i++ → i = 4
    // 	•	mw = nums[4] = 2
    int maxBalancedShipments(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1,mw=nums[0];i<n;i++){
            if(mw>nums[i]){
                cnt++;
                ++i;
            }
            mw=nums[i];
        }
        return cnt;
    }
};