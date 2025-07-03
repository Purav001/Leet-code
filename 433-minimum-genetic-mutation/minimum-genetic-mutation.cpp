class Solution {
public:
    int minMutation(string s, string e, vector<string>& geneBank) {
        // we are using set here because find operation in unordered-set are of O(1) complexity and in vector they are of O(N^2)
        unordered_set<string> bank(geneBank.begin(),geneBank.end());
        if(bank.find(e)==bank.end()) return -1;
        queue<pair<string,int>> q;
        q.push({s,0});
        unordered_map<string,bool> visited;
        visited[s]=true;
        vector<char> ch={'A','C','G','T'};
        while(!q.empty()){
            auto [str,moves]=q.front();
            q.pop();
            if(str==e) return moves;
            for(int i=0;i<8;i++){
                char org=str[i];
                for(char c:ch){
                    if(c==str[i]) continue;
                    str[i]=c;
                    if(!visited[str] && bank.find(str)!=bank.end()){
                        q.push({str,1+moves});
                        visited[str]=true;
                    }
                }
                str[i]=org;
            }
        }
        return -1;
    }
};