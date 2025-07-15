class Solution {
public:
    // greedy approach
    // we store the first and last occurence of every character of s
    // and update the last occurence as we travel in substring 
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();
        vector<int> f(26,n),l(26,-1); // f- first || l-last
        // get the first and last occurence of each char of s
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            f[idx]=min(f[idx],i);
            l[idx]=max(l[idx],i);
        }
        // update the last to get a valid substring 
        // i.e. " acabbbc " for 'a' first and last is [0,2], but "aca" is not valid since we didn't include all the occurence of 'c'
        // so we iterate the substring updating the last 
        for(int i=0;i<26;i++){
            int st=f[i],e=l[i]; // st - start || e - end
            for(int j=st+1;j<e;j++){ // we traverse the substring of s in [first,last] interval
                int idx=s[j]-'a';
                st=min(st,f[idx]);
                e=max(e,l[idx]);
            }
            f[i]=st;
            l[i]=e; // updates the last occurence to make the substring valid
        }
        // by doing this we dont need to check again for the substring with lesser total length, it automatically give the min one
        vector<vector<int>> subs;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(f[idx]==i){ // if it is the first occurence , then it can a valid substring
                int e=l[idx];
                if(!subs.empty() && subs.back()[1]>e) subs.pop_back(); // we found a smaller valid substring that could lead to more number of substrings
                subs.push_back({i,e});
            }
        }
        vector<string> ans;
        for(int i=0;i<subs.size();i++) ans.push_back(s.substr(subs[i][0],subs[i][1]-subs[i][0]+1));
        return ans;
    }
};