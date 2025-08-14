class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        long long ans=0;
        sort(skill.begin(),skill.end());
        int l=0,r=n-1,sum=skill[l]+skill[r];
        while(l<r){
            int temp=skill[l]+skill[r];
            if(temp==sum){
                ans+=1LL*skill[l]*skill[r];
                l++;
                r--;
            }
            else return -1;
        }
        return ans;
    }
};