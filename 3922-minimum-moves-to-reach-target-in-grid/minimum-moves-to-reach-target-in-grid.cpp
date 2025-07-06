class Solution {
public:
    // here for dp we are using map because it is an infinites grid which can extend upto 10^9 so using an vector<vector<>> can cause memory issues
    
    // this way will cause tle because it is an endless grid 
    // so instead of dfs memoisation use bfs

    // map<pair<int,int>,int> dp;
    // int solve(int sx, int sy, int tx, int ty){
    //     if(sx>tx || sy>ty) return 1e9;
    //     if(sx==tx && sy==ty) return 0;
    //     if(dp.count({sx,sy})) return dp[{sx,sy}];
    //     int m=max(sx,sy);
    //     int ans=1e9;
    //     if(sx<tx) ans=min(ans,solve(sx+m,sy,tx,ty));
    //     if(sy<ty) ans=min(ans,solve(sx,sy+m,tx,ty));
    //     return dp[{sx,sy}]=(ans==1e9?1e9:1+ans);
    // }

    int minMoves(int sx, int sy, int tx, int ty) {
        // memoisation 
        // if(sx==tx && sy==ty) return 0;
        // if(sx>tx || sy>ty || (sx==0 && sy==0)) return -1;
        // dp.clear();
        // int ans=solve(sx,sy,tx,ty);
        // return ans==1e9?-1:ans;

        // bfs - in farward direction -- also causes TLE

        // if(sx==tx && sy==ty) return 0;
        // if(sx>tx || sy>ty || (sx==0 && sy==0)) return -1;
        // queue<tuple<int,int,int>> q;
        // // set<pair<int,int>> visited;
        // unordered_set<long long> v;
        // q.push({sx,sy,0});
        // // visited.insert({sx,sy});
        // v.insert({((long long)sx<<32) | sy});
        // while(!q.empty()){
        //     auto [x,y,s]=q.front();
        //     q.pop();
        //     if(x==tx && y==ty) return s;
        //     long long key;
        //     int m=max(x,y);
        //     if(x+m<=tx){
        //         key=((long long)(x+m)<<32 | y);
        //         if(!v.count(key)){
        //             q.push({x+m,y,1+s});
        //             // visited.insert({x+m,y});
        //             v.insert(key);
        //         }
        //     }
        //     if(y+m<=ty){
        //         key=((long long)x<<32|(y+m));
        //         if(!v.count(key)){
        //             q.push({x,y+m,1+s});
        //             // visited.insert({x,y+m});
        //             v.insert(key);
        //         }
        //     }
        // }
        // return -1;

        // due to increasing search space we use backward tracking top decrease number of explorations
        // using the fact that (x,y) can come from only limited number of points 
        // If x > y, and x > 2*y and x is even, we go to (x / 2, y);
        // otherwise, we go to (x - y, y).
        // If y > x, and y > 2*x and y is even, we go to (x, y / 2);
        // otherwise, we go to (x, y - x).
        // If x == y, we can only going to (0, y) or (x, 0) if allowed.

        if(sx==tx && sy==ty) return 0;
        if(sx>tx || sy>ty || (sx==0 && sy==0)) return -1;
        queue<pair<int,int>> q;
        q.push({tx,ty});
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;++i){
                auto [x,y]=q.front();
                q.pop();
                if(x<sx || y<sy) continue;
                if(x==sx && y==sy) return steps;
                if(x>y){
                    if(x>2*y) {
                        if(x%2==0) q.push({x/2,y});
                    }
                    else q.push({x-y,y});
                }
                else if(y>x){
                    if(y>2*x) {
                        if(y%2==0) q.push({x,y/2});
                    }
                    else q.push({x,y-x});
                }
                else {
                    if(sx==0) q.push({0,y});
                    if(sy==0) q.push({x,0});
                }
            }
            ++steps;
        }
        return -1;
    }
};