class Solution {
public:
    // simple dijkstra
    // maintain a dis- time vector to store min time for each neighbor
    // basic idea is that we wait untill the time becomes equal to entry time of room and add 1 for entering the room
    int minTimeToReach(vector<vector<int>>& nums) {
        int n=nums.size(),m=nums[0].size();
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        nums[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [t,x,y]=pq.top();
            pq.pop();
            if(t>=dis[x][y]) continue;
            if(x==n-1 && y==m-1) return t;
            dis[x][y]=t;
            for(auto [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<n && ny<m && dis[nx][ny]==INT_MAX){
                    int nt=max(nums[nx][ny],t)+1;
                    pq.push({nt,nx,ny});
                }
            }
        }
        return -1;
    }
};