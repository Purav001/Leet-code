class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x1=points[i][0],x2=points[j][0];
                int y1=points[i][1],y2=points[j][1];
                if(x1>=x2 && y1<=y2){
                    int st=1;
                    for(int k=0;k<n;k++){
                        if(k==i || k==j) continue;
                        int x=points[k][0],y=points[k][1];
                        if(x>=x2 && x<=x1 && y>=y1 && y<=y2){
                            st=0;
                            break;
                        }
                    }
                    if(st) cnt++;
                }
            }
        }
        return cnt;
    }
};