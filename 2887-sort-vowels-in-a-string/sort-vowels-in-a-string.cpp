class Solution {
public:
    string sortVowels(string s) {
        int n=s.length();
        vector<char> vowel;
        vector<char> isVowel(n,false);
        for(int i=0;i<n;i++){
            char c=tolower(s[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowel.push_back(s[i]);
                isVowel[i]=true;
            }
        }
        sort(vowel.begin(),vowel.end());
        int idx=0;
        for(int i=0;i<n;i++){
            if(isVowel[i]) s[i]=vowel[idx++];
        }
        return s;
    }
};