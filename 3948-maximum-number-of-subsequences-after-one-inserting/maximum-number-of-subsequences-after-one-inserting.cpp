class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        if(n==1) return 0;
        vector<long long> pref(n,0),suff(n,0);
        // pref[i] number of 'L' from begining to i
        // suff[i] number of 'T' from i to end
        // => for every 'C' calculate how many "LCT" subsequences can be formed
        for(int i=0;i<n;i++){
            pref[i]=(s[i]=='L'?1:0);
            suff[i]=(s[i]=='T'?1:0);
        }
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
            suff[n-1-i]+=suff[n-i];
        }
        long long op1=0,op2=0,op3=0,ans=0;
        // op1 - one extra 'L'
        // op2 - one extra 'T'
        // op3 - one extra 'C'
        // we are calculating for very occuring 'C'
        for(int i=0;i<n;i++){
            if(s[i]=='C'){
                op1+=(pref[i]+1)*suff[i]; // add L
                op2+=pref[i]*(suff[i]+1); // add T
                ans+=pref[i]*suff[i]; // original
            }
            else op3=max(op3,pref[i]*suff[i]); // add C
        }
        return max({op1,op2,ans+op3});

    }
};