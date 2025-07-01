class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1,prev=nums[0],n=nums.size();
        if(n<2) return cnt;
        int k=1;
        for(int i=1;i<n;i++){
            if(nums[i]==prev){
                if(cnt<2){
                    cnt++;
                    nums[k++]=nums[i];
                }
            }
            else{
                nums[k++]=nums[i];
                prev=nums[i];
                cnt=1;
            }
        }
        return k;
    }
};