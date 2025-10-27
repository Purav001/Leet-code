class Solution {
public:
    // there should no device in between any two devices , so number of beams from each device on same row are same between two rows 
    // just maintain a count of rows with devices > 0
    // and the sum = cnt[i]*cnt[i-1]
    int numberOfBeams(vector<string>& bank) {
        vector<int> cntDevices;
        for(auto i:bank){
            int cnt=0;
            for(char ch:i) if(ch=='1') cnt++;
            if(cnt>0) cntDevices.push_back(cnt);
        }
        int ans=0;
        for(int i=1;i<cntDevices.size();i++){
            ans+=cntDevices[i]*cntDevices[i-1];
        }
        return ans;
    }
};