class Solution {
public:
    int minTimeToReach(vector<vector<int>>& nums) {
        int n=nums.size(),m=nums[0].size();
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        nums[0][0]=0;
        pq.push({0,0,0});
        int move=0;
        while(!pq.empty()){
            auto [t,x,y]=pq.top();
            pq.pop();
            if(t>=dis[x][y]) continue; // if currTime >= already shortest time then skip
            if(x==n-1 && y==m-1) return t;
            dis[x][y]=t;
            for(auto [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(nx>=0 && ny>=0 && nx<n && ny<m && dis[nx][ny]==INT_MAX){
                    int extra= (x+y)%2+1; // used for alternating the cost (+2 or +1) 
                    // for first move , i.e move from x+y (even) to nx+ny (odd) it takes cost 1
                    // and for next move from x+y (odd) to nx+ny (even) it takes cost 2
                    int nt=max(nums[nx][ny],t)+extra;
                    pq.push({nt,nx,ny});
                }
            }
        }
        return -1;
    }
};