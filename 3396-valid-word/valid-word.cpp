class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;
        int v=0,c=0;
        for(char ch:word){
            if(!isalnum(ch)) return false;
            ch=tolower(ch);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') v++;
            else if(ch > '9')c++;
        }
        if( c==0 || v==0 ) return false;
        return true;
    }
};