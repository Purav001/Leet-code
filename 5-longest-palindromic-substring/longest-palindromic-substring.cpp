class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int l=0,a=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if (dp[i][j] > l && i + j == n + dp[i][j]) {
                        l = dp[i][j];
                        a = i;
                    }
                }
                else dp[i][j]=0;
            }
        }
        int start=a-l;
        return s.substr(start,l);
    }
};