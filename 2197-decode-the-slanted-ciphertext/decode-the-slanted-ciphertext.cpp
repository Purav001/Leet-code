class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows==1) return encodedText;
        int s=encodedText.length();
        int m=rows,n=s/m; // n-number of columns
        int k=0;
        vector<vector<char>> sub(m,vector<char>(n)); // make a matrix to decode the the text
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sub[i][j]=encodedText[k++];
            }
        }
        string ans="";
        int i=0,j=0; // traverse the matrix
        while(j<n){
            int row=i,col=j;
            while(row<m && col<n){
                ans+=sub[row][col];
                row++;
                col++;
            }
            j++;
        }
        ans.erase(ans.find_last_not_of(' ') + 1); // deletes all the ' ' after last non space character
        return ans;
    }
};