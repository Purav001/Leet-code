class Solution {
public:
    bool solve(vector<int> nums,int i,int d){
        int n=nums.size();
        int dir=(d==0?-1:1);
        while(i<n && i>=0){
            i+=dir;
            if (i < 0 || i >= n) break;
            if(nums[i]>0){
                nums[i]--;
                dir=(dir==-1?1:-1);
            }
        }
        for(int j=0;j<n;j++){
            if(nums[j]!=0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                bool right=solve(nums,i,1);
                bool left=solve(nums,i,0);
                if(right && left) cnt+=2;
                else if(right || left) cnt++;
            }
        }
        return cnt;
    }
};