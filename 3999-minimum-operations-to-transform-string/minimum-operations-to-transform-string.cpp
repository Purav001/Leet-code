class Solution {
public:
    int minOperations(string s) {
        // naive approach 

        // vector<int> freq(27,0);
        // for(char c:s) freq[c-'a']++;
        // int cnt=0;
        // for(int i=1;i<26;i++){
        //     if(freq[i]==0) continue;
        //     else{
        //         freq[i+1]+=freq[i];
        //         freq[i]=0;
        //         cnt++;
        //     }
        // }
        // return cnt;

        // better approach

        int ans=0;
        for(char c:s) ans=max(ans,(26-(c-'a'))%26);
        return ans;
    }
};