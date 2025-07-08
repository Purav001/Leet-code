class Solution {
public:
    struct comp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a.second<b.second;
        }
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++) p.push_back({capital[i],profits[i]});
        sort(p.begin(),p.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>, comp> pq;
        int i=0;
        while(k--){
            while(i<n && p[i].first<=w){
                pq.push(p[i]);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top().second;
            pq.pop();
        }
        return w;
    }
};