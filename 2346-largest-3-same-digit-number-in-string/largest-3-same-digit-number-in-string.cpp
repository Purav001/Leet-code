class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        string ans="";
        for(int i=0;i<=n-3;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                string temp=num.substr(i,3);
                if(temp>ans) ans=temp; // compare lexographically
                // to handle if there are more than one good integers in num
                // "000" and "999" - so it should return "999"
            }
        }
        return ans;
    }
};