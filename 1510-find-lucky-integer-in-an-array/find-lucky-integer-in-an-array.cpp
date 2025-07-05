class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1,n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            int cnt=1;
            while(i<n && arr[i]==arr[i-1]){
                cnt++;i++;
            }
            if(cnt==arr[i-1]) ans=arr[i-1];
        }
        return ans;
    }
};