class Solution {
public:
    // greedy
    // the basic idea is to store all the frineds that cannot communicate with each oother 
    // and teach them a common languaghe that is known to some 
    // answer will the lang that is known to more number of people

    int minimumTeachings(int m, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int n=languages.size();
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<n;i++) mp[i+1].insert(languages[i].begin(),languages[i].end());
        unordered_set<int> problem; // store all the frineds that cannot communicate 
        for(auto f:friendships){
            int u=f[0],v=f[1];
            bool canTalk=false;
            for(auto i:mp[v]){
                if(mp[u].count(i)){
                    canTalk=true;
                    break;
                }
            }
            if(!canTalk){
                problem.insert(u);
                problem.insert(v);
            }
        }
        if(problem.empty()) return 0; // all can communicate

        int ans=INT_MAX;
        for(int i=1;i<=m;i++){
            int cnt=0;
            for(int j:problem){
                if(!mp[j].count(i)) cnt++; // count the number of friends that dont know this language
            }
            ans=min(ans,cnt); // store the min number of friends that need to be taught
        }
        return ans;
    }
};