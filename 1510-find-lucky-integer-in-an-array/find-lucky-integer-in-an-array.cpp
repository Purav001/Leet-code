class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxi=-1;
        for(int i:arr) mp[i]++;
        for(auto i:mp) if(i.second==i.first) maxi=max(maxi,i.second);
        return maxi;
    }
};