class Solution {
public:
    // we need to find the minimum cost to reach m-1,n-1 from 0
    // looks easy but has one catch in base case
    // while we are on 0,0 we need to add the cost of entering 0,0 cell that is 1, so that is why this base case has been used and we add 1 to ans
    vector<vector<vector<long long>>> dp;
    long long solve(vector<vector<int>>& nums,int i,int j,int t,int m,int n){
        if(i>=m || j>=n) return LLONG_MAX;
        if(i==m-1 && j==n-1) return 0;
        if(dp[i][j][t]!=-1) return dp[i][j][t];
        long long ans=0;
        if(t==0) ans=nums[i][j]+solve(nums,i,j,1,m,n);
        else{
            long long v1=LLONG_MAX,v2=LLONG_MAX;
            if(i+1<m) v1=(1LL*(i+2)*(j+1))+solve(nums,i+1,j,0,m,n);
            if(j+1<n) v2=(1LL*(i+1)*(j+2))+solve(nums,i,j+1,0,m,n);
            ans=min(v1,v2);
        }
        return dp[i][j][t]=ans;
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        // memoisation

        // dp.resize(m,vector<vector<long long>>(n,vector<long long>(2,-1)));
            
        // return 1+solve(waitCost,0,0,1,m,n);

        // tabulation

        // dp.resize(m+1,vector<vector<long long>>(n+1,vector<long long>(2,1e15)));
        // dp[m-1][n-1][0]=dp[m-1][n-1][1]=0;
        // for(int i=m-1;i>=0;i--){
        //     for(int j=n-1;j>=0;j--){
        //         if(i==m-1 && j==n-1) continue;
        //         long long down= (i+1<m)? (1LL*(i+2)*(j+1))+dp[i+1][j][0]:1e15;
        //         long long right= (j+1<n)? (1LL*(i+1)*(j+2))+dp[i][j+1][0]:1e15;
        //         dp[i][j][1]=min(down,right);
        //         dp[i][j][0]=waitCost[i][j]+dp[i][j][1];
        //     }
        // }
        // return 1+dp[0][0][1];

        // space optimisation - most optimised version

        // c= for current row - i row -- o for odd and e for even
        // p= for next row - i+1 row -- o for odd and e for even
        vector<long long> co(n+1,1e15),ce(n+1,1e15);
        vector<long long> po(n+1,1e15),pe(n+1,1e15);
        co[n-1]=ce[n-1]=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                long long down= (1LL*(i+2)*(j+1))+pe[j];
                long long right= (1LL*(i+1)*(j+2))+ce[j+1];
                co[j]=min(down,right);
                ce[j]=waitCost[i][j]+co[j];
            }
            pe=ce;
            po=co;
        }
        return 1+po[0];
    }
};