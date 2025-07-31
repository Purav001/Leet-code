class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
       unordered_set<int> ans;
       unordered_set<int> prev;
       for(int i:arr){
        unordered_set<int> curr;
        curr.insert(i);
        for(int j:prev) curr.insert(j|i);
        prev=curr;
        ans.insert(curr.begin(),curr.end());
       }
       return ans.size();
    }
};