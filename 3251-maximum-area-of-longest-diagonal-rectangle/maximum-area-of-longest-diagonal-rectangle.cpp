class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        double diagonal=0;
        for(auto rec:dimensions){
            int len=rec[0],wid=rec[1];
            double dig=sqrt(pow(len,2)+pow(wid,2));
            if(dig>diagonal){
                ans=len*wid;
                diagonal=dig;
            }
            else if(dig==diagonal) ans=max(ans,len*wid);
        }
        return ans;
    }
};