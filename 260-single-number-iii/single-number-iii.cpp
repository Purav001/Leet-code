class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return nums;
        int all=0;
        for(int i:nums) all^=i;
        int x=0,y=0;
        int db= all & -((unsigned int)all); // -all = ~all +1 so that the first set bit in original number can be & with 1 at that place ans rest all bits become 0
        for(int i:nums){
            if(i & db) x^=i;
            else y^=i;
        }
        return {x,y};

    }
};