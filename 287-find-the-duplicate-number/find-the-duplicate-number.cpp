class Solution {
public:
    // we ca consider the elements of array as linked list , and the dulicate element is consider to be cycle forming element eg 1-2-3-2 after 3 again to 2

    //  Floyd’s Tortoise and Hare (cycle detection)

    int findDuplicate(vector<int>& nums) {
        int s=nums[0];
        int f=nums[0];
        // detect intersection point
        do{
            s=nums[s];
            f=nums[nums[f]];
        }while(s!=f);
        s=nums[0];
        // find the enterance to the cycle ( duplicate element )
        while(s!=f){
            s=nums[s];
            f=nums[f];
        }
        return s;
    }
};