class Solution {
    static const int K = 31; // safe for inputs up to 1e9
    vector<long long> cnt;           // cnt[k] = number of values with bit-length k (2^(k-1))
    vector<long long> steps;         // steps[k] = ceil(k/2)
    vector<long long> prefWeighted;  // prefWeighted[k] = sum_{i=1..k} cnt[i] * steps[i]
public:
    Solution() {
        cnt.assign(K + 1, 0);
        steps.assign(K + 1, 0);
        prefWeighted.assign(K + 1, 0);

        for (int k = 1; k <= K; ++k) {
            cnt[k] = 1LL << (k - 1);       // 2^(k-1)
            steps[k] = (k + 1) / 2;        // ceil(k/2)
            prefWeighted[k] = prefWeighted[k - 1] + cnt[k] * steps[k];
        }
    }


    // count numbers within [L, R] that lie inside [blockL, blockR]
    static long long CountInBlock(long long L, long long R, long long blockL, long long blockR) {
        long long a = max(L, blockL);
        long long b = min(R, blockR);
        return (a <= b) ? (b - a + 1) : 0LL;
    }


    // compute bit length for positive integer x (assumes x > 0)
    static int BitLength(unsigned x) {
        // __builtin_clz is undefined for 0, so we don't call it with 0.
        return 32 - __builtin_clz(x);
    }


    // compute minimum operations for a single range [l, r]
    long long MinOpsForRange(int l, int r) {
        if (l > r) return 0;
        int kl = BitLength((unsigned)l);
        int kr = BitLength((unsigned)r);

        long long S = 0; // total individual reductions required
        // partial lower block (bit-length kl)
        long long lowL = 1LL << (kl - 1);
        long long lowR = (1LL << kl) - 1;
        long long c1 = CountInBlock(l, r, lowL, lowR);
        S += c1 * ((kl + 1) / 2);

        if (kr != kl) {
            // partial upper block (bit-length kr)
            long long upL = 1LL << (kr - 1);
            long long upR = (1LL << kr) - 1;
            long long c2 = CountInBlock(l, r, upL, upR);
            S += c2 * ((kr + 1) / 2);

            // full middle blocks kl+1 .. kr-1 via prefix sums
            if (kl + 1 <= kr - 1) {
                S += prefWeighted[kr - 1] - prefWeighted[kl];
            }
        }

        int dMax = (kr + 1) / 2;
        long long ops = max((long long)dMax, (S + 1) / 2); // max(dMax, ceil(S/2))
        return ops;
    }


    long long minOperations(vector<vector<int>>& queries) {
        // brute

        // int cnt=0,n=queries.size();
        // for(int i=0;i<n;i++){
        //     int l=queries[i][0],r=queries[i][1];
        //     priority_queue<int> pq;
        //     for(int j=l;j<=r;j++) pq.push(floor(log10(j)/log10(4))+1);
        //     while(!pq.empty()){
        //         int a=pq.top();pq.pop();
        //         int b=pq.top();pq.pop();
        //         cnt++;
        //         a--;b--;
        //         if(a>0) pq.push(a);
        //         if(b>0) pq.push(b);
        //     }
        // }
        // return cnt;

        // o(1) per query

        long long ans = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans += MinOpsForRange(l, r);
        }
        return ans;
    }
};