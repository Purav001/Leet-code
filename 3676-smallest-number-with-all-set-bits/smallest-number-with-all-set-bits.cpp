class Solution {
public:
    int smallestNumber(int n) {
        int x=0;
        while(n>0){
            n=n>>1;
            x=x<<1|1;
        }
        return x;
    }
};