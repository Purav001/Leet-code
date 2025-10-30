class Solution {
public:

    // O(n^2) - brute -> works for this question because constraints are not tight

    // bool solve(vector<int> nums,int i,int d){
    //     int n=nums.size();
    //     int dir=(d==0?-1:1);
    //     while(i<n && i>=0){
    //         i+=dir;
    //         if (i < 0 || i >= n) break;
    //         if(nums[i]>0){
    //             nums[i]--;
    //             dir=(dir==-1?1:-1);
    //         }
    //     }
    //     for(int j=0;j<n;j++){
    //         if(nums[j]!=0) return false;
    //     }
    //     return true;
    // }

    int countValidSelections(vector<int>& nums) {
        int n=nums.size();

        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         bool right=solve(nums,i,1);
        //         bool left=solve(nums,i,0);
        //         if(right && left) cnt+=2;
        //         else if(right || left) cnt++;
        //     }
        // }
        // return cnt;

        vector<int> pref(n,0),suf(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+nums[i]; // prefix sum
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+nums[i]; // suffix sum

        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int lsum=0,rsum=0;
                if(i>0) lsum=pref[i-1];
                if(i<n-1) rsum=suf[i+1];

                if(lsum==rsum) cnt+=2;
                else if(lsum-1==rsum) cnt++;
                else if(lsum==rsum-1) cnt++;
            }
        }
        return cnt;
    }
};