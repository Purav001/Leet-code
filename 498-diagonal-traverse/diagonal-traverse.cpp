class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();

        // ok! but takes extra space

        // vector<vector<int>> store(m+n);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         int sum=i+j;
        //         if(sum%2==0) store[sum].insert(store[sum].begin(),mat[i][j]);
        //         else store[sum].push_back(mat[i][j]);
        //     }
        // }
        // vector<int> ans;
        // for(auto dig:store) ans.insert(ans.end(),dig.begin(),dig.end());
        // return ans;

        int i=0,j=0;
        bool up=true;
        vector<int> ans;
        while(ans.size()<m*n){
            ans.push_back(mat[i][j]);
            if(up){
                if(j==n-1){ // when we reach top element while moving up
                    i++;
                    up=false; // downwards
                }
                else if(i==0){
                    j++;
                    up=false;
                }
                else{ // normal iteration for up
                    i--;
                    j++;
                }
            }
            else{
                if(i==m-1){ // when we reach the lowest element while moving down
                    j++;
                    up=true; // upwards
                }
                else if(j==0){
                    i++;
                    up=true;
                }
                else{ // normal iteration for down
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};