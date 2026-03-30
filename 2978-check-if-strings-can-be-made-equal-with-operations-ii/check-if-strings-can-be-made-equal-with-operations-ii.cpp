class Solution {
public:
    // catch - two strings will be equal if the characters at odd possition adn even possition in bith strings are same
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> e;
        unordered_map<char, int> o;
        
        for(int i=0; i<s1.length(); i+=2) {
            e[s1[i]]++;
        }
        for(int i=1; i<s1.length(); i+=2) {
            o[s1[i]]++;
        }
        for(int i=0; i<s1.length(); i+=2) {
            e[s2[i]]--;
        }
        for(int i=1; i<s1.length(); i+=2) {
            o[s2[i]]--;
        }

        for(auto [i,j]:e){
            if(j!=0) return false;
        }
        for(auto [i,j]:o){
            if(j!=0) return false;
        }

        return true;
    }
};