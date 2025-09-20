class Router {
public:
    int time=0,n;
    set<tuple<int,int,int>> router;
    queue<tuple<int,int,int>> q;
    unordered_map<int,vector<int>> dest;
    Router(int memoryLimit) {
        n=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(router.count({timestamp,source,destination})) return false;
        if(router.size()==n){
            auto [t,s,d]=q.front();
            q.pop();
            router.erase({t,s,d});
            dest[d].erase(dest[d].begin());
        }
        router.insert({timestamp,source,destination});
        q.push({timestamp,source,destination});
        dest[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto [t,s,d]=q.front();
        q.pop();
        router.erase({t,s,d});
        dest[d].erase(dest[d].begin());
        return {s,d,t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int cnt=0;
        if(dest.count(destination)){
            auto& ts=dest[destination];
            auto it1 = lower_bound(ts.begin(),ts.end(),startTime);
            auto it2 = upper_bound(ts.begin(),ts.end(),endTime);
            cnt= distance(it1,it2);
        }
        return cnt;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */