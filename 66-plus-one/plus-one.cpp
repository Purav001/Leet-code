class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        if(digits[n-1]!=9) digits[n-1]+=1;
        else{
            int carry=1,i=n-2;
            digits[n-1]=0;
            bool done=false;
            while(carry && i>=0){
                if(digits[i]!=9){
                    digits[i--]+=1;
                    carry=0;
                    done = true;
                    break;
                }
                else{
                    digits[i--]=0;
                }
            }
            if(!done){
                reverse(digits.begin(),digits.end());
                digits.push_back(1);
                reverse(digits.begin(),digits.end());
            }
        }
        return digits;
    }
};