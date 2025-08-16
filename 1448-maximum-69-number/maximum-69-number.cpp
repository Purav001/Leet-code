class Solution {
public:
    int maximum69Number (int num) {
        // naive approach

        int n=num,temp=0;
        while(n>0){
            int t=n%10;
            temp=temp*10+t;
            n/=10;
        }
        int ans=0,st=1;
        while(temp>0){
            int t=temp%10;
            if(t==6 && st){
                t=9;
                st=0;
            }
            ans=ans*10+t;
            temp/=10;
        }
        return ans;
    }
};