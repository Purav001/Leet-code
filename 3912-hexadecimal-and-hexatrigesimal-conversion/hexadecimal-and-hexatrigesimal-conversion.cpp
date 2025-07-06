class Solution {
public:
    string solve(long long x, int b){
        string ans;
        char c;
        while(x>0){
            int n=x%b;
            if(n>9) c='A'+n-10;
            else c='0'+n;
            ans= c+ans;
            x/=b;
        }
        return ans.empty()?"0":ans;
    }
    string concatHex36(int n) {
        long long x=n*n,y=n*n*n;
        return solve(x,16)+solve(y,36);
    }
};