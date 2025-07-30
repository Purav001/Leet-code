class Solution {
public:
    unordered_map<int,pair<int,int>> mp={{1,{1,0}},{0,{0,1}}};
    void dfs(vector<vector<char>>& board,int i,int j, int parity){
        board[i][j]='.';
        auto [x,y]=mp[parity];
        if(i+x<board.size() && j+y<board[0].size() && board[i+x][j+y]=='X') dfs(board,i+x,j+y,parity);
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    cnt++;
                    if(i+1<m && board[i+1][j]=='X') dfs(board,i,j,1); // 1 - vertical
                    if(j+1<n && board[i][j+1]=='X') dfs(board,i,j,0); // 0 - horizontal
                }
            }
        }
        return cnt;
    }
};