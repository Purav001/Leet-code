class Solution {
public:
    void solve(int i,int n,int k, vector<vector<int>>& ans, vector<int>& sub){
        if(sub.size()==k){
            ans.push_back(sub);
            return;
        }
        // we can also use j<=n simply , but using this will reduce unnecesary calls
        for(int j=i;j<=n-(k-sub.size())+1;j++) {
            sub.push_back(j);
            solve(j+1,n,k,ans,sub);
            sub.pop_back();
        }
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(1,n,k,ans,sub);
        return ans;
    }
};