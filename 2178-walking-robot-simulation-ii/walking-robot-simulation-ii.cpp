class Robot {
public:
    int n,m;
    int x=0,y=0;
    unordered_map<string,pair<int,int>> coord={{"East",{0,1}},{"West",{0,-1}},{"North",{1,0}},{"South",{-1,0}}};
    unordered_map<string,string> dirs={{"East","North"},{"North","West"},{"West","South"},{"South","East"}};
    string dir="East";
    Robot(int width, int height) {
        n=height;
        m=width;
    }
    
    void step(int num) {
        int perimeter=2*(n+m-2);
        if (perimeter>0) num%=perimeter;
        if(num==0 && x==0 && y==0){
            dir="South";
            return;
        }
        auto [i,j]=coord[dir];
        while(num--){
            int nx=x+i,ny=y+j;
            if(nx>=n || nx<0 || ny>=m || ny<0){
                dir=dirs[dir];
                i=coord[dir].first;
                j=coord[dir].second;
            }
            x+=i;
            y+=j;
        }
    }
    
    vector<int> getPos() {
        return {y,x};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */