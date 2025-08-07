class Solution {
public:
    // we count the number of rabbits saying a number x
    // if the number of rabbits saying x are greater than x+1 => there are rabbits of different colour that have same x+1 rabbits of same colour
    // for eg let us say rabits saying 1 are 3 => there are two rabits of c colour and 2 more rabbits of y colour
    // that is why we do "ceil((double)i.second/(i.first+1))*(i.first+1)"
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int> mp;
        for(int i:answers) mp[i]++;
        // for(auto& i:mp){
        //     if(i.second>(i.first+1)){
        //         int j=i.second%(i.first+1);
        //         i.second/=(i.first+1);
        //         if(j!=0) i.second++;
        //     }
        //     else i.second=1;
        // }
        // int ans=0;
        // for(auto i:mp) ans+=(i.first+1)*i.second;

        // or

        int ans=0;
        for(auto i:mp) ans+= ceil((double)i.second/(i.first+1))*(i.first+1);
        return ans;
    }
};