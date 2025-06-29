class Solution {
public:
    // this is a case of partition DP called - front partition
    // we satrt by partioning from start we only partition if the substr ia palindrome 
    // if it is a palindrome we count the number ofurther cuts and store the min one
    // vector<int> dp;
    // int solve(string s, int i){
    //     if(i==s.length()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     string temp="";
    //     int mini=INT_MAX;
    //     for(int j=i;j<s.length();j++){
    //         temp+=s[j];
    //         if(isPalindrome(temp)){
    //             int cuts=1+solve(s,j+1);
    //             mini=min(mini,cuts);
    //         }
    //     }
    //     return dp[i]=mini;
    // }
    bool isPalindrome(string t){
        int n=t.length();
        int l=0,r=n-1;
        while(l<r) if(t[l++]!=t[r--]) return false;
        return true;
    }
    int minCut(string s) {
        int n=s.length();
        // memoisation

        // dp.resize(n,-1);
        // return solve(s,0)-1;

        // tabulation

        vector<int> dp(n+1,0);
        vector<vector<bool>> isPal(n,(vector<bool>(n,false)));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || isPal[i + 1][j - 1])) isPal[i][j]=true;
            }
        }
        for(int i=n-1;i>=0;i--){
            string temp="";
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isPal[i][j]){
                    int cuts=1+dp[j+1];
                    mini=min(mini,cuts);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};