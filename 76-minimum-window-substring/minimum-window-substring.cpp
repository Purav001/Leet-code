class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        unordered_map<char,int> mp; // store freq of all elements in t tha should be present in substring of s
        int l=0,r=0,cnt=0,minLen=INT_MAX,stInd=-1;
        while(r<t.size()){
            mp[t[r]]++;
            r++;
        }
        r=0;
        while(r<s.size()){
            if(mp[s[r]]>0) cnt++; // if the char is needed in t or not
            mp[s[r]]--;
            while(cnt==t.size()){ // prune the window - if the window is valid
                if((r-l+1)<minLen){
                    minLen=r-l+1;
                    stInd=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return stInd==-1?"":s.substr(stInd,minLen);
    }
};
