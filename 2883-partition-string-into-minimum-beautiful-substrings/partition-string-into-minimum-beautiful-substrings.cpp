class Solution {
public:
    // somewhat like partition DP on strings
    // basically we need to place cuts , such that the substring is beautiful

    // dp[i]- minimum number of substrings toll index i that are beautiful 

    // vector<int> dp;
    // int solve(string s,int i){
    //     if(i==s.length()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int mini=INT_MAX;
    //     string temp="";
    //     for(int j=i;j<s.length();j++){
    //         temp+=s[j];
    //         if(isBeautiful(temp)){
    //             int cuts=solve(s,j+1);
    //             if(cuts!=INT_MAX) mini=min(mini,1+cuts);
    //         }
    //     }
    //     return dp[i]=mini;
    // }

    bool isBeautiful(string s){
        if(s[0]=='0') return false;
        long long num=0;
        for(char c:s){
            num=num*2+(c-'0');
        }
        if(num<=0) return false;
        while(num%5==0) num/=5;
        return num==1;
    }

    int minimumBeautifulSubstrings(string s) {
        int n=s.length();

        // memoisation

        // dp.resize(n,-1);
        // int ans=solve(s,0);
        // return ans==INT_MAX?-1:ans;

        // tabulation

        vector<int> dp(n+1,1e9);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isBeautiful(temp)) dp[i]=min(dp[i],1+dp[j+1]);
            }
        }
        return dp[0]>=1e9?-1:dp[0];
    }
};