class Solution {
    
    int markDeadFromAlive = 100;
    int markAliveFromDead = 101;
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int row = size(board);
        int column = size(board[0]);
        
        vector<pair<int, int>> directions = { 
            {-1, -1}, { -1, 0}, { -1, 1}, 
            {0,-1}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        
        auto isValid = [row, column](int i, int j) -> bool {
            if (!( i >= 0 && i < row)) { return false; }
            if (!( j >= 0 && j < column)) { return false; }
            return true;
        };
        
        auto getCount = [&] (int i, int j) -> int {
            int count = 0;
            for (auto x: directions) {
                if ( isValid( i + x.first, j + x.second ) ) {
                    count += ( board[i + x.first][j + x.second] == 1 
                              || board[i + x.first][j + x.second] == markDeadFromAlive ? 1 : 0 ); 
                }
            }
            return count;
        };
        
        for( int i = 0; i < size(board); i++ ) {
            for( int j = 0; j < size(board[0]); j++ ) {
                int count = getCount(i, j);
                if ( count == 3 ) {
                    if ( board[i][j] == 0 ) board[i][j] = markAliveFromDead;
                } else if( count < 2 ) {
                    if ( board[i][j] == 1 ) board[i][j] = markDeadFromAlive;
                } else if ( count > 3 ) {
                    if ( board[i][j] == 1 ) board[i][j] = markDeadFromAlive;
                }
            }
        }
        
        for( int i = 0; i < size(board); i++ ) {
            for( int j = 0; j < size(board[0]); j++ ) {
                if (board[i][j] == markDeadFromAlive) {
                    board[i][j] = 0;
                } else if (board[i][j] == markAliveFromDead) {
                    board[i][j] = 1;
                }
            }
        }
    }
};