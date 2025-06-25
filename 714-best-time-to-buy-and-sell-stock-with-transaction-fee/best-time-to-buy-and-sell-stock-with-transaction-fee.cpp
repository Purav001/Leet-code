class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // tabulation

        // vector<vector<int>> dp(n+1,vector<int>(2,0));

        // space optimisation

        vector<int> prev(2,0),cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j) cur[j]= max((-prices[i]+prev[0]),prev[1]);
                else cur[j]= max((prices[i]-fee+prev[1]),prev[0]);
            }
            prev=cur;
        }
        return prev[1];
    }
};