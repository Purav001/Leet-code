class FoodRatings {
public:

    struct cmp{
        bool operator()(const pair<int,string>& a, const pair<int,string>& b){
            if(a.first==b.first) return a.second>b.second; // smaller lexographical string first
            return a.first<b.first; // max rating first
        }
    };
    unordered_map<string,map<string,int>> mp; // stores the rating of all the food
    unordered_map<string,string> ftoc; // store cuisines of food so that we need not search for foods in rating map
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>> cuiFoodOrder;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp[cuisines[i]][foods[i]]=ratings[i];
            ftoc[foods[i]]=cuisines[i];
            cuiFoodOrder[cuisines[i]].push({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=ftoc[food];
        mp[cuisine][food]=newRating;
        cuiFoodOrder[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        // brute

        // int max=-1;
        // string ans="";
        // for(auto f:mp[cuisine]){
        //     if((f.second>max) || (f.second==max && f.first<ans)){
        //         ans=f.first;
        //         max=f.second;
        //     }
        // }
        // return ans;

        auto &pq=cuiFoodOrder[cuisine];
        while(!pq.empty()){
            auto [rating,item]=pq.top();
            if(mp[cuisine][item]==rating) return item;
            pq.pop();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */