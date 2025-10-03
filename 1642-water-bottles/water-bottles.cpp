class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            int drink=numBottles/numExchange;
            int empty=numBottles%numExchange;
            ans+=drink;
            numBottles=drink+empty;
        }
        return ans;
    }
};