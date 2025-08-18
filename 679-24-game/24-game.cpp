class Solution {
public:
    // we need to try all the combinations - therefore we will solve the question by recursion
    // idea is to choose any two numbers a and b and perform all 6 operations on it
    // a+b
    // a-b
    // b-a
    // a*b
    // a/b
    // b/a
    // after getting the result we again call the function with the remaining numbers of input array and this number obtained by performing operation

    bool solve(vector<double>& nums){
        int n=nums.size();
        if(n==1) return abs(nums[0]-24.0)<0.000001; // precission check
        // as we are using double and the question has real division so there can be data loss like- 10/3=3.3333..
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double a=nums[i],b=nums[j]; // choose two numbers
                vector<double> op=calculate(a,b); // perfrom 6 operations
                vector<double> next;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j) next.push_back(nums[k]); // remaining numbers
                }
                for(auto o:op){
                    next.push_back(o);
                    if(solve(next)) return true;
                    next.pop_back(); // if we dont get answer with this operation result we move to next operation result
                }
            }
        }
        return false;
    }
    vector<double> calculate(double a,double b){ // perfrom operations
        vector<double> ans;
        ans.push_back(a+b);
        ans.push_back(a-b);
        ans.push_back(b-a);
        ans.push_back(a*b);
        ans.push_back(a/b);
        ans.push_back(b/a);
        return ans;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i:cards) nums.push_back((double)i);
        return solve(nums);
    }
};