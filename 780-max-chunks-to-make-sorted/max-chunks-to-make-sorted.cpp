class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int i=0,maxi=-1;
        while(i<n){
            maxi=max(maxi,arr[i]);
            if(maxi==i) ans++;
            i++;
        }
        return ans;
    }
};