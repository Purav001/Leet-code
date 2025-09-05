class Solution {
public:
    // same as partition DP on strings
    // cut the string if it is valid

    // vector<int> dp;
    // int solve(string s,int i){
    //     if(i==s.length()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int mini=INT_MAX;
    //     vector<int> freq(26,0);
    //     for(int j=i;j<s.length();j++){
    //         freq[s[j]-'a']++;
    //         if(isBalanced(freq)){
    //             int cuts=1+solve(s,j+1);
    //             if(cuts<mini) mini=cuts;
    //         }
    //     }
    //     return dp[i]=mini;
    // }

    bool isBalanced(vector<int>& freq){
        int val=-1;
        for(int f:freq){
            if(f==0) continue;
            if(val==-1) val=f;
            else if(f!=val) return false;
        }
        return true;
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.length();

        // memoisation

        // dp.resize(n,-1);
        // return solve(s,0);

        // tabulation

        vector<int> dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(isBalanced(freq)) dp[i]=min(dp[i],1+dp[j+1]);
            }
        }
        return dp[0];
    }
};