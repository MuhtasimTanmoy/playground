class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        pair<int, int> pos;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == 'R')
                    pos.first = i, pos.second = j;
        
        int res = 0;
        for (int i = pos.second + 1; i < board[0].size(); i++) {
            if (board[pos.first][i] == 'B') break;
            if (board[pos.first][i] == 'p') { res++; break; }
        }
        
        for (int i = pos.second - 1; i >= 0; i--) {
            if (board[pos.first][i] == 'B') break;
            if (board[pos.first][i] == 'p') { res++; break; }
        }
        
        for (int i = pos.first + 1; i < board[0].size(); i++) {
            if (board[i][pos.second] == 'B') break;
            if (board[i][pos.second] == 'p') { res++; break; }
        }
        
        for (int i = pos.first - 1; i >= 0; i--) {
            if (board[i][pos.second] == 'B') break;
            if (board[i][pos.second] == 'p') { res++; break; }
        }
        return res;
    }
};