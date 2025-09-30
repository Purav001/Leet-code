class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string,vector<string>> mp;
        for(string i:s){
            string key=i;
            sort(key.begin(),key.end());
            mp[key].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto& p:mp) ans.push_back(p.second);
        return ans;
    }
};