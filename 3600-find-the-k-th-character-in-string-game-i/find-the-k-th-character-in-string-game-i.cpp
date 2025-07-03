class Solution {
public:
    string solve(string s){
        int n=s.length();
        string ans="";
        for(char ch:s){
            if(ch>='a' && ch<'z') ans+= ch+1;
            if(ch=='z') ans+= 'a';
            if(ch>='A' && ch<'Z') ans+= ch+1;
            if(ch=='Z') ans+= 'A';
        }
        return ans;
    }
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string temp=s;
            s+=solve(temp);
        }
        return s[k-1];
    }
};