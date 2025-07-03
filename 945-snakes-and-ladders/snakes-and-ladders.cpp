class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> flat(n*n+1,-1);
        flat[0]=0;
        int ind=1;
        bool lr=true;
        for(int i=n-1;i>=0;i--){
            if(lr){
                for(int j=0;j<n;j++) flat[ind++]=board[i][j];
            } 
                
            else {
                for(int j=n-1;j>=0;j--) flat[ind++]=board[i][j];
            }
                
            lr=!lr;
        }
        queue<pair<int,int>> q;
        vector<bool> visited(n*n+1,false);
        q.push({1,0});
        visited[1]=true;
        while(!q.empty()){
            auto [pos,moves]=q.front();
            q.pop();
            if(pos==n*n) return moves;
            for(int i=1;i<=6;i++){
                if(pos+i>n*n ) break; 
                int next= flat[pos+i]==-1?pos+i:flat[pos+i];
                if(!visited[next]){
                    q.push({next,1+moves});
                    visited[next]=true;
                }
            }
        }
        return -1;
    }
};