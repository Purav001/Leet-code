class Solution {
public:
    // tree pruning + graph traversal
    // 2 phase pruning
    // first:
    // remove all the leaf nodes that do not have any coins

    // second:
    // remove the nodes from which teh coins can be collected by from another nodes ,without traversing them

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        // phaase 1 pruning - removing  leaf nodes without coins
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==1 && coins[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(deg[u]==0) continue;
            deg[u]=0;
            for(auto v:adj[u]){
                if(deg[v]>0){
                    deg[v]--;
                    if(deg[v]==1 && coins[v]==0) q.push(v);
                }
            }
        }

        // phase 2 pruning - remove the nodes from where the coins can be collected from its neighbors
        
        for(int s=0;s<2;s++){ // since we can move 2 steps, we need to prune 2 times
            for(int i=0;i<n;i++){
                if(deg[i]==1) q.push(i);
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                if(deg[u]==0) continue;
                deg[u]=0;
                for(auto v:adj[u]){
                    if(deg[v]>0) deg[v]--;
                }
            }
        }
        
        // count remaining edges

        int cnt=0; // number of edges
        for(auto e:edges){
            if(deg[e[0]]>0 && deg[e[1]]>0) cnt++; // the nodes with degree>0 are still useful and we need to traverse them
        }
        return cnt*2;
    }
};