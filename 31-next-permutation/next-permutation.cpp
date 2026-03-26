class Solution {
public:
    // we need to make smallest possible increase int the array

    // catch - in the given array - if it is not sorted - the last part of array is usually descending
    // this is the breaking point 

    // [1,2,3,6,5,4]
    // 3 is te break point 
    // swap 3 and 4(first greater element from end) and reverse the array from 6 (break point + 1) till end
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int bp=-1; // breakpoint where order becomes descending
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;
            }
        }
        if(bp==-1){ // if the array is already descendingy sorted eg [4,3,2,1] -> [1,2,3,4]
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;n>=0;i--){
            if(nums[i]>nums[bp]){
                swap(nums[i],nums[bp]);
                break;
            }
        }
        reverse(nums.begin()+bp+1,nums.end());
    }
};
    