class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles; // first drink all the filled bottles
        while(numBottles>=numExchange){
            numBottles-=(numExchange++); // then remove first batch of bottles
            numBottles++; // drink the exchanged bottle
            ans++;
        }
        return ans;
    }
};