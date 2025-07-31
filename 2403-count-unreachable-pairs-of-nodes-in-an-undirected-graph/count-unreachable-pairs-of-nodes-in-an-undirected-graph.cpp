class Solution {
public:
    void dfs(vector<vector<int>>& adj,int node,int& cnt,vector<bool>& visited){
        visited[node]=true;
        cnt++;
        for(int nei:adj[node]){
            if(!visited[nei]) dfs(adj,nei,cnt,visited);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        long long ans=0;
        int islands=n;
        // count number of connected nodes in each connection and store it
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int cnt=0;
                dfs(adj,i,cnt,visited);
                // calculate the number of pairs
                ans+=1LL*(cnt)*(islands-cnt);
                islands-=cnt;
            }
        }
        return ans;
    }
};