class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double t=log10(n)/log10(4);
        return t==floor(t);
    }
};