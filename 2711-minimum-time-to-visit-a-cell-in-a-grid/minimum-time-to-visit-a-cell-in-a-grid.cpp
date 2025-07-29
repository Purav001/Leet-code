class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        int n =grid.size(),m=grid[0].size();
        vector<vector<int>> time(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,0,0});
        time[0][0]=0;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto [t,x,y] = pq.top();
            pq.pop();
            if(x==n-1 && y==m-1) return t;
            for(auto [dx,dy]: dir){
                int nx=dx+x,ny=dy+y;
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int wait= ((grid[nx][ny]-t)%2==0)?1:0;
                    int nt=max(t+1,grid[nx][ny]+wait);
                    if(nt<time[nx][ny]){
                        time[nx][ny]=nt;
                        pq.push({nt,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};