class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>> mp; // movie -> price -> shop
    unordered_map<int,unordered_map<int,int>> unrented; // unrented movies on a shop with price
    unordered_map<int,unordered_map<int,int>> rented; // rented movies from a shop
    set<tuple<int,int,int>> pq; // rented movies in general;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto entry:entries){
            int shop=entry[0],movie=entry[1],price=entry[2];
            unrented[shop][movie]=price;
            mp[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int cnt=0;
        for(auto it=mp[movie].begin();it!=mp[movie].end() && cnt<5; it++ ,cnt++) ans.push_back(it->second);
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price=unrented[shop][movie];
        unrented[shop].erase(movie);
        mp[movie].erase({price, shop});
        rented[shop][movie]=price;
        pq.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price=rented[shop][movie];
        rented[shop].erase(movie);
        unrented[shop][movie]=price;
        mp[movie].insert({price, shop});
        pq.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt=0;
        for(auto it=pq.begin();it!=pq.end() && cnt<5 ;it++,cnt++){
            ans.push_back({get<1>(*it),get<2>(*it)});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */