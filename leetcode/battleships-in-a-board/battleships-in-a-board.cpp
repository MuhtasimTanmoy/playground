class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int i, int j) {
        if (!( i >= 0 && i < size(board))) return false;
        if (!( j >= 0 && j < size(board[0]))) return false;
        if (board[i][j]=='.') { return false; }
        if (board[i][j]=='M') { return false; }
        return true;
    }
    
     pair<int,int> getDirection(vector<vector<char>>& board, int i, int j) {
        if (isValid(board, i+1, j)) { return make_pair(1, 0); }
        if (isValid(board, i, j+1)) { return make_pair(0, 1); }
        if (isValid(board, i-1, j)) { return make_pair(-1, 0); }
        if (isValid(board, i, j-1)) { return make_pair(0, -1); }
        return make_pair(0, 0);
    }
    
    void markShip(vector<vector<char>>& board, int i, int j) {
        auto direction = getDirection(board, i, j);
        if ( direction.first == 0 && direction.second == 0 ) return;
        board[i+direction.first][j+direction.second] = 'M';
        markShip(board, i+direction.first, j+direction.second);
    }
    
    int countBattleships(vector<vector<char>>& board) {        
        int countBattleShip = 0;
        for(int i = 0; i < size(board); i++ ) {
            for(int j = 0; j < size(board[0]); j++) {
                if (board[i][j]=='X') {
                    countBattleShip++;
                    markShip(board, i, j);
                }
            }
        }
        return countBattleShip;
    }
};