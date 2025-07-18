class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1],t=edge[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({passingFees[0],0,0});
        vector<vector<int>> dp(n,vector<int>(maxTime+1,1e9));
        // we use dp because there are multipe paths to reach same node
        // dp[i][t] tells the minimum cost to reach node i in time -t
        while(!pq.empty()){
            auto [fee,t,u]=pq.top();
            pq.pop();
            if(u==n-1) return fee;
            for(auto [v,time]:adj[u]){
                int nt=t+time; // nt- new time
                if(nt>maxTime) continue;
                int nc=fee+passingFees[v]; // nc- new cost
                if(dp[v][nt]>nc){
                    dp[v][nt]=nc;
                    pq.push({nc,nt,v});
                }
            }
        }
        return -1;
    }
};