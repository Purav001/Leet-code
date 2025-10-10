class Solution {
public:
    // we need to distribute the cookies to k children such that we get minimum unfairness
    // -> maximum sum of distribution among each children is minimum

    // chech for each combination of assignement and give the minimum one
    // because we are cheching for all the combinations , we will use BACKTRACKING + early PRUNING

    int ans=INT_MAX;
    void solve(vector<int>& cookies,vector<int>& kids,int ind,int k){
        if(ind==cookies.size()){
            ans=min(ans,*max_element(kids.begin(),kids.end()));
            return;
        }
        for(int i=0;i<kids.size();i++){
            kids[i]+=cookies[ind];
            if(*max_element(kids.begin(),kids.end())<ans) solve(cookies,kids,ind+1,k); // pruning - if the max element exceeds the minUnfair val -> no need to discover that path
            kids[i]-=cookies[ind]; // backtrack
            if(kids[i]==0) break; // if the element gets 0 , then its time to try it with new children , backtrack
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kids(k,0);
        solve(cookies,kids,0,k);
        return ans;
    }
};