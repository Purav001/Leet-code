class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> broken;
        for(char ch: brokenLetters) broken.insert(ch);
        int cnt=0,n=text.length();
        bool canType=true;
        for(int i=0;i<n;i++){
            if(text[i]==' ') {
                if(canType) cnt++;
                canType=true;
            }
            else if(broken.count(text[i])) canType=false;
        }
        if(canType) cnt++;
        return cnt;
    }
};