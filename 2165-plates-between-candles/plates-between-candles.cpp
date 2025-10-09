class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.length();
        // Here count[i][0] -> count of candles from 0 -> i
	    // and count[i][1] -> count of plates from 0 -> i
        vector<vector<int>> count(n,vector<int>(2));

        count[0]=s[0]=='*'?vector<int>{0,1}:vector<int>{1,0};
        for(int i=1;i<n;i++){
            count[i]= s[i]=='*'?vector<int>{count[i-1][0],count[i-1][1]+1}:vector<int>{count[i-1][0]+1,count[i-1][1]};
        }
        vector<int> ans;
        for(auto query:queries){
            int lo=query[0],hi=query[1];
            if(s[lo]=='*') lo=lower_bound(count.begin()+lo,count.begin()+hi,vector<int>{count[lo][0]+1,-1})-count.begin();
            if(s[hi]=='*') hi=upper_bound(count.begin()+lo,count.begin()+hi-1,vector<int>{count[hi][0],-1})-count.begin();
            ans.push_back(count[hi][1]-count[lo][1]);
        }
        return ans;
    }
};