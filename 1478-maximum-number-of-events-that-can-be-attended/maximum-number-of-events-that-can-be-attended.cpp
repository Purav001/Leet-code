class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) {
        int n=nums.size();
        if(n==1 || n==0) return n;
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int day=0,i=0,cnt=0;
        while(i<n || !pq.empty()){
            if(pq.empty()) day=nums[i][0];
            while(i<n && nums[i][0]==day){
                pq.push(nums[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<day) pq.pop();
            if(!pq.empty()){
                pq.pop();
                cnt++;
                day++;
            }
        }
        return cnt;
    }
};