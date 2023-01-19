class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        auto n = 3;
        vector<int> row(n, 0), col(n, 0);
        int diag = 0, antidiag = 0;
        bool turn = true;
        for (auto move: moves) {
            auto val = turn ? 1: -1;
            auto x = move[0], y = move[1];
            
            row[x] += val;
            col[y] += val;
            
            if (x == y) diag += val;
            if (x + y == n - 1) antidiag += val;
            
            if (abs(row[x]) == n 
                || abs(col[y]) == n 
                || abs(diag) == n 
                || abs(antidiag) == n) 
                return turn ? "A": "B";
            
            turn = !turn;
        }
        return moves.size() == n * n ? "Draw": "Pending";
    }
};