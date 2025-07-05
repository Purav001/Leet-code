class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> r,c,b; // r- row, c-column, b-3*3box
            for(int j=0;j<9;j++){
                // chech row
                if(board[i][j]!='.'){
                    if(r.count(board[i][j])) return false;
                    r.insert(board[i][j]);
                }
                // check column
                if(board[j][i]!='.'){
                    if(c.count(board[j][i])) return false;
                    c.insert(board[j][i]);
                }
                // check 3*3 box
                char ch=board[3*(i/3)+j/3][3*(i%3)+(j%3)];
                if(ch!='.'){
                    if(b.count(ch)) return false;
                    b.insert(ch);
                }
            }
        }
        return true;
    }
};