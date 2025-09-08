class Solution {
public:
    bool non0(int n){
        while(n>0){
            int i=n%10;
            if(i==0) return false;
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int a=i,b=n-i;
            if(non0(a) && non0(b)){
                return {a,b};
            }
        }
        return {-1,-1};
    }
};