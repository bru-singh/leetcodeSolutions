class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int res = 0;

        // tc: O(n*m) 
        // sc: O(1) because we are modifing the current board only

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='X'){
                    // is this X the start of any battleship
                    // this will be the start of a battleship,
                    // if i-1, j and j-1, i are not X
                    if((i==0 or board[i-1][j]!='X') and (j==0 or board[i][j-1]!='X'))
                        res++;
                }
            }
        }
        return res;
    }
};