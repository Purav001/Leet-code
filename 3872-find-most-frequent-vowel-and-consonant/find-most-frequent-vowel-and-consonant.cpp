class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowel,consonant;
        int m1=0,m2=0;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowel[c]++;
                m1=max(m1,vowel[c]);
            }
            else {
                consonant[c]++;
                m2=max(m2,consonant[c]);
            }
        }
        return m1+m2;
    }
};