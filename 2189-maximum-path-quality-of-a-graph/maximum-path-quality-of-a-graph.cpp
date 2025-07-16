class Solution {
public:
    // basically it is classic graph traversal problem 
    // in which we are traversing the graph repeatedly untill time becomes greater than maxTime
    // we use visited array to track the number of visits of node in a path , so that the queality of each node is only added once
    int quality=0;
    void dfs(vector<int>& values, vector<vector<pair<int,int>>>& adj, int mt,vector<int>& visited,int node,int t, int q){
        visited[node]++;
        if(node==0 && t<=mt) quality=max(quality,q);
        for(auto [v,w]:adj[node]){
            if(t+w<=mt) dfs(values,adj,mt,visited,v,t+w,q+(visited[v]==0?values[v]:0));
            // by visited array we are checking that wheather in this path e are visiting node v for first time or not
            // if yes then we are adding the value[v] to curr-quality
            // else we are moving with the same curr-quality
        }
        visited[node]--; // backtrack
        // backtracking is important because after traversing a path , when we are in another path, the node still remains visited and it results to ambiguty
        // hence we need to backtrack the value
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1],t=edge[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<int> visited(n,0);
        dfs(values,adj,maxTime,visited,0,0,values[0]);
        return quality;
    }
};