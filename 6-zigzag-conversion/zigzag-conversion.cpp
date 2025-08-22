class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1 | numRows>=n) return s;
        vector<string> zigzag(numRows,"");
        int row=0,dir=1;
        for(char c:s){
            zigzag[row]+=c;
            if(row==0) dir=1;
            else if(row==numRows-1) dir=-1;
            row+=dir;
        }
        string ans="";
        for(auto str:zigzag) ans+=str;
        return ans;
    }
};