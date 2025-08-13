class Solution {
public:
    bool isPowerOfThree(int n) {
        // loop

        // if(n<=0) return false;
        // while(n>1){
        //     if(n%3!=0) return false;
        //     n/=3;
        // }
        // return n==1;

        // log

        if(n<=0) return false;
        double log= log10(n)/log10(3); // base changing formula
        return log==floor(log); // check wheather the log value is integer or not 
    }
};