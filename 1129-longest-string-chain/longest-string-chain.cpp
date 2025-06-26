class Solution {
public:
    bool comp(string s, string t){
        int n=s.length(),m=t.length();
        if(n-m!=1) return false;
        int l=0,r=0;
        // we start from startin gindex of both the string and travere
        // if the string letter matches we move both the pointers , if not we only move pointer of s 
        // if both the pointer reaches end the chain is valid , else it is not

        // eg: bcda | bdc n=4,m=3, l=0,r=0
        // l=0 r=0  b|b l++ r++
        // l=1 r=1 c|d l++
        // l=2 r=1 d|d l++ r++
        // l=3 r=2 a|c l++
        // l=4 r=2 , as both the ponter does not reach end , hence it is not valid chain

        while(l<n){
            if(s[l]==t[r]){
                l++;r++;
            }
            else l++;
        }
        if(l==n && r==m) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        // we need to sort the array as the question talks about sequence not subsequence , to make it longest subsequence we will sort the array
        sort(words.begin(),words.end(),[](string& a, string& b){
            return a.length()<b.length();
        });
        vector<int> dp(n+1,1);
        // here dp[i] tells us that length f longest substring chain till index i
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(comp(words[i],words[j])) dp[i]=max(dp[i],1+dp[j]);
            }
            if(dp[i]>maxi) maxi=dp[i];
        }
        return maxi;
    }
};