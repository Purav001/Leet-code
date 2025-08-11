class Solution {
public:
    const int MOD= 1e9+7;
    // Binary exponention
    // Any exponent can be expressed as a sum of powers of 2 in binary form.
    // 13^10 = 1101^2 = 8+4+1
    // base^13 = base^8 * base^4 * base^1

    // Example — modPow(3, 13) with MOD = 1000
	// 1.	exp = 13 (binary 1101)
    //     res = 1, base = 3
    //     LSB = 1 → res = (1×3) % 1000 = 3
    //     base = 3² = 9, exp = 6

    // 2.	exp = 6 (binary 110)
    //     LSB = 0 → skip res update
    //     base = 9² = 81, exp = 3

    // 3.	exp = 3 (binary 11)
    //     LSB = 1 → res = (3×81) % 1000 = 243
    //     base = 81² = 6561 % 1000 = 561, exp = 1

    // 4.	exp = 1 (binary 1)
    //     LSB = 1 → res = (243×561) % 1000 = 923
    //     base = (561²) % 1000 = 721, exp = 0

    //     Loop ends → Answer: 923

    long long inv(long long base, long long exp){
        long long res=1;
        while(exp>0){
            if(exp & 1) res=(res*base)%MOD;
            base=(base*base)%MOD;
            exp>>=1;
        }
        return res;
    }
    vector<int> productQueries(int m, vector<vector<int>>& queries) {
        vector<long long> powers;
        for(int i=0;i<31;i++){
            if(m&(1<<i)) powers.push_back(1LL<<i);
        }
        sort(powers.begin(),powers.end());
        int n=powers.size();
        vector<long long> pre(n);
        pre[0]=powers[0]%MOD;
        for(int i=1;i<n;i++) pre[i]=(pre[i-1]*powers[i])%MOD;
        vector<int> ans;
        for(auto q:queries){
            int l=q[0],r=q[1];
            if(l==0) ans.push_back(pre[r]);
            // else ans.push_back(pre[r]/pre[l-1]);

            //here ( pre[r]/pre[l-1] ) becomes wrong as (a/b)(mod P) != (a/b)mod P
            // insted (a/b)(mod p) = a*b^p-2 (mod P)
            else ans.push_back((pre[r]*inv(pre[l-1],MOD-2))%MOD);
        }
        return ans;
    }
};