class Solution {
public:
    struct cmp{
        bool operator()(pair<int,double>& a,pair<int,double>& b){
            return a.second<b.second;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<int,double>,vector<pair<int,double>>,cmp> pq;
        for(int i=0;i<n;i++){
            double org=classes[i][0]/(double)classes[i][1];
            double chng=(classes[i][0]+1)/(double)(classes[i][1]+1);
            pq.push({i,chng-org});
        }
        while(extraStudents>0){
            auto [i,c]=pq.top();
            pq.pop();
            classes[i][0]++;
            classes[i][1]++;
            double org=classes[i][0]/(double)classes[i][1];
            double chng=(classes[i][0]+1)/(double)(classes[i][1]+1);
            pq.push({i,chng-org});
            extraStudents--;
        }
        double ans=0.0;
        for(auto c:classes) ans+=c[0]/(double)c[1];
        return ans/n;
    }
};