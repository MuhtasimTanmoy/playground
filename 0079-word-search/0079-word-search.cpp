// GETS TLE
/*
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        auto isValid = [&](int x, int y) {
            if (x < 0) return false;
            if (y < 0) return false;
            if (x >= board.size()) return false;
            if (y >= board[0].size()) return false;
            return true;
        };
        
        auto key = [](int x, int y) {
            auto k = to_string(x) + "-" + to_string(y);
            return k;
        };
        
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        function<bool(int, int, int)> go = [&](int x, int y, int index) {
            if (index == word.size() - 1) return board[x][y] == word[index];
            if (board[x][y] != word[index]) return false;
            
            auto c = board[x][y];
            board[x][y] = '*';
            
            bool isFound = false;
            for (auto dir: dirs) {
                auto nextX = x + dir.first, nextY = y + dir.second;
                auto nextKey = key(nextX, nextY);
                if (isValid(nextX, nextY) && board[nextX][nextY] != '*') isFound |= go(nextX, nextY, index + 1);
            }
            board[x][y] = c;
            return isFound;
        };
        
        for (int i = 0; i < board.size(); i++) 
            for (int j = 0; j < board[0].size(); j++) 
                if (board[i][j] == word[0])
                    if (go(i, j, 0)) 
                        return true;
       return false;
};
*/

class Solution {
public:
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
        if(n == word.size()) return true; 
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        board[i][j] = '0';
        bool status = DFS(board, word, i + 1, j, n + 1) ||  
                      DFS(board, word, i, j + 1, n + 1) ||  
                        DFS(board, word, i - 1, j, n + 1) || 
                        DFS(board, word, i, j - 1, n + 1);
        
        board[i][j] = word[n];
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        return false;
    }
};