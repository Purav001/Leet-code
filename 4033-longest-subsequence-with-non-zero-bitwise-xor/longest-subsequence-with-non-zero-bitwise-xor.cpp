class Solution {
public:
        // The XOR of all elements is either zero or non-zero (in our case, simply positive integer).

        // If total XOR != 0
        // → Take ALL elements return length

        // If total XOR=0
        //     Case 1: has at least one positive.
        //         → Remove 1 element:
        //             return length−1
        //     Case 2: all elements are 0
        //         → return 0
        
    int longestSubsequence(vector<int>& nums) {
        int XOR=0;
        bool pos=0;
        for(int i:nums){
            pos|= i>0;
            XOR^=i;
        }
        return pos?nums.size()-(XOR==0):0;
    }
};
