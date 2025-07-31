class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,-1},{0,1},{1,-1},{1,1},{-1,1},{-1,-1}};
    int cntMines(vector<vector<char>>& board,int x,int y){
        int cnt=0;
        for(auto [dx,dy]:dir){
            int nx=x+dx,ny=y+dy;
            if(nx>=0 && ny>=0 && nx<board.size() && ny<board[0].size() && board[nx][ny]=='M') cnt++;
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& board,int x,int y){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]!='E') return;
        int mines= cntMines(board,x,y);
        if(mines>0){
            board[x][y]='0'+mines;
            return;
        }
        board[x][y]='B';
        for(auto [dx,dy]:dir) dfs(board,x+dx,y+dy);
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x=click[0],y=click[1];
        if(board[x][y]=='M') board[x][y]='X';
        else dfs(board,x,y);
        return board;
    }
};