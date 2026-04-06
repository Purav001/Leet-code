class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        auto curr= make_pair(0,0),dir=make_pair(0,1);
        set<pair<int,int>> s;
        for(int i=0;i<obstacles.size();i++){
            s.insert(make_pair(obstacles[i][0],obstacles[i][1]));
        }
        int ans=0;
        int n=commands.size(),i=0;
        while(i<n){
            int cmd=commands[i++];
            auto& [x,y]=curr;
            auto& [j,k]=dir;
            if(cmd==-1){
                if(j==0 && k==1) dir=make_pair(1,0);
                else if(j==0 && k==-1) dir=make_pair(-1,0);
                else if(j==1 && k==0) dir=make_pair(0,-1);
                else dir=make_pair(0,1);
            }
            else if(cmd ==-2){
                if(j==0 && k==1) dir=make_pair(-1,0);
                else if(j==0 && k==-1) dir=make_pair(1,0);
                else if(j==1 && k==0) dir=make_pair(0,1);
                else dir=make_pair(0,-1);
            }
            else{
                for(int l=0;l<cmd;l++){
                    if(s.find({x+j,y+k})!=s.end()) break;
                    curr=make_pair(x+j,y+k);
                    ans=max(ans,(x*x)+(y*y));
                }
            }
        }
        return ans;
    }
};