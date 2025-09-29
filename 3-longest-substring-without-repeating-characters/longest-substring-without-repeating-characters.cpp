class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> chars;
        int len=0,n=s.length();
        int l=0,r=0;
        while(r<n){
            chars[s[r]]++;
            while(chars[s[r]]>1) chars[s[l++]]--;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};