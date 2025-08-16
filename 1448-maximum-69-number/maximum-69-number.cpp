class Solution {
public:
    int maximum69Number (int num) {
        // naive approach

        // int n=num,temp=0;
        // while(n>0){
        //     int t=n%10;
        //     temp=temp*10+t;
        //     n/=10;
        // }
        // int ans=0,st=1;
        // while(temp>0){
        //     int t=temp%10;
        //     if(t==6 && st){
        //         t=9;
        //         st=0;
        //     }
        //     ans=ans*10+t;
        //     temp/=10;
        // }
        // return ans;

        // better thinking

        int a=-1; // store the place where first 6 occurs from left
        for(int n=num,d=0;n>0;n/=10,d++){
            int r=n%10;
            if(r==6) a=d;
        }
        return (a==-1)?num:int(num+3*pow(10,a));
    }
};