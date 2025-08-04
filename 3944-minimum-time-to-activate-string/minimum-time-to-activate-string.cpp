class Solution {
public:
    // due to constraints of question , we binary search on t to find the minimum time
    // basically for every mid we check whether the string is active or not 
    // we check active strings by 
    // total number of substrings of s : (n)(n+1)/2 - number of clean substrings :i.e the substrings with no *
    bool valid(string s,vector<int>& order,int k,int t){
        int n=s.size();
        vector<char> temp(s.begin(),s.end());
        for(int i=0;i<=t;i++) temp[order[i]]='*';
        long long total= 1LL*n*(n+1)/2,clean=0; // clean- substrings with no *
        int len=0; // lengtgh to find number of clean substrings
        for(int i=0;i<=n;i++){
            if(i==n || temp[i]=='*'){
                clean+=1LL*len*(len+1)/2;
                len=0;
            }
            else len++;
        }
        return (total-clean)>=k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int n=order.size();
        int l=0,h=n-1,ans=-1;
        while(l<=h){
            int mid= h+(l-h)/2;
            if(valid(s,order,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};