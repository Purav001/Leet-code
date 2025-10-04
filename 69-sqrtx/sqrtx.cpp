class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int l=0,r=x/2;
        while(l<=r){
            int mid= l+(r-l)/2;
            long long num=1ll*mid*mid;
            if(num==x) return mid;
            else if(num<x){
                l=mid+1;
            }
            else r=mid-1;
        }
        return r;
    }
};