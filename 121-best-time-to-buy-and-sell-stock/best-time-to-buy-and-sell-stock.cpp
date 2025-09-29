class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=INT_MAX,ans=0; 
       for(int i:prices){
        if(i<buy) buy=i;
        else ans=max(ans,i-buy);
       }
       return ans;
    }
};