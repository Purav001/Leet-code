class Solution {
public:
    // observation :

    // MHT root is always the center of tree
    // leaf nodes can never be the answer because they form MAX height tree
    // the center can be one or two adjacent nodes


    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> leaf;
        for(int i=0;i<n;i++){
            if(degree[i]==1) leaf.push(i);
        }
        int remain=n;
        while(remain>2){
            int leaves=leaf.size();
            remain-=leaves;
            for(int i=0;i<leaves;i++){
                int node=leaf.front();
                leaf.pop();
                for(int j:adj[node]){
                    degree[j]--;
                    if(degree[j]==1) leaf.push(j);
                }
            }
        }
        vector<int> ans;
        while(!leaf.empty()){
            ans.push_back(leaf.front());
            leaf.pop();
        }
        return ans;
    }
};