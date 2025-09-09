class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // bfs approach

        // queue<int> q;
        // q.push(1);
        // int time=1;
        // while(!q.empty()){
        //     if(time==n) break;
        //     time++;
        //     int l=q.size();
        //     for(int i=0;i<l;i++){
        //         int t=q.front();
        //         q.pop();
        //         if((t+forget)==time) continue;
        //         if(time>=(t+delay)) {
        //             q.push(t);
        //             q.push(time);
        //         }
        //         else q.push(t);
        //     }
        // }
        // return q.size();

        // dp - bottom up

        // dp[i]- number of people knowing the secret on day i
        // dp[i-delay] - number of people that discovered the secret on i-delya day and can share the secret today
        // dp[i-forget] - number of people that discovered the secret on i-forget day and now will forget the secret today

        const int MOD=1e9+7;
        vector<int> dp(n+1,0);
        dp[1]=1;
        long long share=0;
        for(int i=2;i<=n;i++){
            if((i-delay)>=1) share=(share+dp[i-delay])%MOD;
            if((i-forget)>=1) share=(share-dp[i-forget]+MOD)%MOD;
            dp[i]=share%MOD;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++) if(i>=1) ans=(ans+dp[i])%MOD;
        return ans;
    }
};