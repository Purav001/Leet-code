class Solution {
public:
    // we have to make a directed graph out of connections (a,b,w) & (b,a,1/w)
    // traverse the graph for each query and keep on mutliplying w on very traversal to an edge
    unordered_map<string,vector<pair<string,double>>> adj;
    bool dfs(string a,string b,unordered_set<string>& visited,double& res,double cur){
        if(a==b){
            res=cur;
            return true;
        }
        visited.insert(a);
        for(auto [v,w]:adj[a]){
            if(!visited.count(v)){
                if(dfs(v,b,visited,res,cur*w)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        // make graph
        for(int i=0;i<n;i++){
            string u=equations[i][0],v=equations[i][1];
            double val=values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }

        vector<double> ans;
        // traverse queries
        for(auto i:queries){
            string a=i[0],b=i[1];
            // if either a or b does not exist in graph
            if(!adj.count(a) || !adj.count(b)){
                ans.push_back(-1.0);
                continue;
            }
            // if start and end of query are same
            if(a==b){
                ans.push_back(1.0);
                continue;
            }
            unordered_set<string> visited;
            double res=-1.0;
            dfs(a,b,visited,res,1.0);
            ans.push_back(res);
        }
        return ans;
    }
};