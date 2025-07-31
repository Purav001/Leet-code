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
        vector<int> sub;
        // count number of connected nodes in each connection and store it
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int cnt=0;
                dfs(adj,i,cnt,visited);
                sub.push_back(cnt);
            }
        }
        long long sum=0;
        for(int i:sub) sum+=i;
        long long ans=0;
        // calculate the number of pairs
        for(int i=0;i<sub.size();i++){
            int el=sub[i];
            sum-=el;
            ans+=1LL*el*sum;
        }
        return ans;
    }
};