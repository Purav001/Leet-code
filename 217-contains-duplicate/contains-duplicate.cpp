class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> distinct;
        for(int i:nums){
            if(distinct.count(i)) return true;
            distinct.insert(i);
        }
        return false;
    }
};