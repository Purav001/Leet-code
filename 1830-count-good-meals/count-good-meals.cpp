class Solution {
public:
    const int MOD=1e9+7;
    int countPairs(vector<int>& deliciousness) {
        vector<int> pow;
        for(int i=0;i<=21;i++) pow.push_back(1<<i);// as the constraints rae too large, precompute the powers of 2
        unordered_map<int,int> cnt; // fo a curr number x check whether there are number y such that x+y is in pow
        long long ans=0;
        for(int i:deliciousness){
            for(auto p:pow){
                int y=p-i;
                if(cnt.find(y)!=cnt.end()){
                    ans=(ans+cnt[y])%MOD;
                }
            }
            cnt[i]++;
        }
        return ans;
    }
};