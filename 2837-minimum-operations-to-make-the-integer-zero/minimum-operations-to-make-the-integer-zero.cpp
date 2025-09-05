class Solution {
public:
    // we have to make num1 to 0 
    // let us assume that num1 becomes 0  after k operations
    // after k opperations 

    // num1=( 2^i1 + 2^i2 ..... + 2^ik) + k * num2
    // => num1 - k * num2 = s = ( 2^i1 + 2^i2 ..... + 2^ik)

    // min values of s can be k - when all i are 0
    // and max value can be k * 2^60

    // and k lies in [1,60]

    // __builtin_popcountll(s) -> number of set bits in binary representation of s -> which tell us the powers of 2 used to make s
    // __builtin_popcountll(S) <=k && k<=s

    int makeTheIntegerZero(int num1, int num2) {
        for(int k=1;k<=60;k++){
            long long s=num1-1ll*k*num2;
            if(s<0) continue;

            // int ones=0;
            // long long temp=s;
            // while(temp>0){
            //     ones+=(temp&1);
            //     temp>>=1;
            // }
            // if(ones<=k) return k;

            if(__builtin_popcountll(s)<=k && k<=s) return k; // using inbuilt function
        }
        return -1;
    }
};