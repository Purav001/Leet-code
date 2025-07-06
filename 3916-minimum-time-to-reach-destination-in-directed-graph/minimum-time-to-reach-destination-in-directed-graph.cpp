class Solution {
public:
    // basically we need to find out the minimum time to reach n-1 node
    // so we use dijkstra 
    // there is one catch we can choose to be on same node or go to another node
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>> adj(n);
        for(auto edge:edges) adj[edge[0]].push_back({edge[1],edge[2],edge[3]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> dist(n,1e9);
        dist[0]=0;
        while(!pq.empty()){
            auto [t,u]=pq.top();
            pq.pop();
            if(u==n-1) return t;
            if(t>dist[u]) continue;
            // if we want to remain on same node
            if(t+1<dist[u]){
                dist[u]=t+1;
                pq.push({dist[u],u});
            }
            for(auto [v,s,e]:adj[u]){
                if(t>=s && t<=e){
                    // if we want to move ahead and it is permisible
                    if(t+1<dist[v]){
                        dist[v]=t+1;
                        pq.push({dist[v],v});
                    }
                }
                else if(t<s){
                    // if t<s and there we want to move to next node so we take time s+1 to reach there
                    if(s+1<dist[v]){
                        dist[v]=s+1;
                        pq.push({dist[v],v});
                    }
                }
            }
        }
        return -1;
    }
};