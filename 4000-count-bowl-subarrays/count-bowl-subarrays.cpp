class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n,-1),next(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            prev[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            next[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prev[i]!=-1 && next[i]!=n) ans++;
        }
        return ans;
    }
};