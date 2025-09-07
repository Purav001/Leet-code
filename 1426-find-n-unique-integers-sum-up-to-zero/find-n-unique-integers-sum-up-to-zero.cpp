class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        vector<int> ans;
        int j=7;
        if(n%2!=0){
            for(int i=0;i<n/2;i++){
                if(i==0){
                    ans.push_back(3);
                    ans.push_back(4);
                }
                else ans.push_back(j);
                ans.push_back(-j);
                j++;
            }
        }
        else {
            for(int i=0;i<n/2;i++){
                ans.push_back(j);
                ans.push_back(-j);
                j++;
            }
        }
        return ans;

    }
};