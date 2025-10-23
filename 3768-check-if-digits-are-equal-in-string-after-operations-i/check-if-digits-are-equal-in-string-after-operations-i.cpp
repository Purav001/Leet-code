class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string temp="";
            for(int i=0;i<s.length()-1;i++){
                int n=((s[i]-'0')+(s[i+1]-'0'))%10;
                temp+=to_string(n);
            }
            s=temp;
        }
        return s[0]==s[1];
    }
};