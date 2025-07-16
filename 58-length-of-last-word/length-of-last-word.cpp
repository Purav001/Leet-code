class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int l=0,r=0,status=1;
        int len=0;
        while(r<n){
            if(s[r]!=' '){
                if(status==0){
                    status=1;
                    l=r;
                    len=r-l+1;
                }
                else len=r-l+1;
            }
            else status=0;
            r++;
        }
        return len;
    }
};