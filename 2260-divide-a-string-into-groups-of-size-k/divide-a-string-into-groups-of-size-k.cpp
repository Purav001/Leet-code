class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i=0;
        while(i<s.length()){
            string sub="";
            for(int j=i;j<i+k;j++){
                if(j<s.length()) sub+=s[j];
                else sub+=fill;
            }
            ans.push_back(sub);
            i+=k;
        }
        return ans;
    }
};