class Solution {
public:
    // dijkstra
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX)); // store minimum time to reach a point (i,j)
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],0,0});
        while(!pq.empty()){
            auto [t,x,y]=pq.top();
            pq.pop();
            if(x==n-1 && y==n-1) return t;
            for(auto [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    int time=max(t,grid[nx][ny]);
                    if(dist[nx][ny]>time){
                        dist[nx][ny]=time;
                        pq.push({time,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};