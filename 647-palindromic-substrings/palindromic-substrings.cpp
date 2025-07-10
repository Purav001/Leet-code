class Solution {
public:
    // so basically we need to find the number of palindromic substrings
    // if 'a' is palindroma than 'xax' is also a palindrome 
    // so we expand about the center in left and right direction

    // if palindrome length is odd the center lies at n/2 and if it is even the center lies between two positions
    // so assuming all palindrome substrings are odd lengthed we get - n centers 
    // and if even we get - n-1 centers
    // => n+n-1 centers

    //  eg: "aba"
    //  centers             type
    //      0           odd(at 'a')
    //      1           even(between "ab")
    //      2           odd(at 'b')
    //      3           even(between "bc")
    //      4           odd(at 'c')
    int countSubstrings(string s) {
        int n=s.length(),cnt=0;
        for(int i=0;i<2*n-1;i++){
            int l=i/2, r=l+(i%2);
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;r++;
            }
        }
        return cnt;
    }
};