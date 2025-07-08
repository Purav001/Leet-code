class Solution {
public:
    struct comp{
        bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b){
            return get<0>(a)>get<0>(b);
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,comp> pq;
        for(int i=0;i<nums1.size() && i<k;i++) pq.push({nums1[i]+nums2[0],i,0});
        vector<vector<int>> ans;
        while(!pq.empty() && ans.size()<k){
            auto [x,i,j]=pq.top();
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size()) pq.push({nums1[i]+nums2[j+1],i,j+1});
        }
        return ans;
    }
};