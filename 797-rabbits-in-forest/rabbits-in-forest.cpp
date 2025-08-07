class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int> mp;
        for(int i:answers) mp[i]++;
        for(auto& i:mp){
            if(i.second>(i.first+1)){
                int j=i.second%(i.first+1);
                i.second/=(i.first+1);
                if(j!=0) i.second++;
            }
            else i.second=1;
        }
        int ans=0;
        for(auto i:mp) ans+=(i.first+1)*i.second;
        return ans;
    }
};