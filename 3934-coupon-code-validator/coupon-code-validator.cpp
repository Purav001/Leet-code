class Solution {
public:
    bool valid(string s){
        if(s.empty()) return false;
        for(char c:s){
            if(!isalnum(c) && c!='_') return false;
        }
        return true;
    }
    bool find(string s,unordered_map<string,int> st){
        if(st.find(s)!=st.end()) return true;
        return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<pair<int,string>> sub;
        if(n==0) return {};
        unordered_map<string,int> st={{"electronics",0}, {"grocery",1}, {"pharmacy",2}, {"restaurant",3}};
        for(int i=0;i<n;i++){
            if(!isActive[i]) continue;
            if(valid(code[i]) && find(businessLine[i],st)) sub.push_back({st[businessLine[i]],code[i]});
        }
        sort(sub.begin(),sub.end());
        vector<string> ans;
        for(auto i:sub) ans.push_back(i.second);
        return ans;
    }
};