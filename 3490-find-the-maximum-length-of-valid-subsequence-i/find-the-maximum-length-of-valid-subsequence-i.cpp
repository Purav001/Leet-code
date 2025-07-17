class Solution {
public:
    // basically we need a sequence with either same parity , or alternating parity
    // either all even , or all odds
    // or even-odd or odd-even sequence
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return n;
        int even=0,odd=0;
        for(int i:nums){
            if(i%2==0) even++;
            else odd++;
        }
        int evenodd=0,oddeven=0;
        // evenodd - counter for sequence starting with even element
        // oddeven - counter for sequence starting with odd element
        int parity=0; // even
        for(int i:nums){
            if(i%2==parity){
                evenodd++;
                parity=!parity;
            }
        }
        parity=1; // odd
        for(int i:nums){
            if(i%2==parity){
                oddeven++;
                parity=!parity;
            }
        }
        return max({even,odd,evenodd,oddeven});
    }
};