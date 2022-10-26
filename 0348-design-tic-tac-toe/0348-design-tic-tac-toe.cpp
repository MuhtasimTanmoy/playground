// class TicTacToe {
// public:
//     TicTacToe(int n) {
        
//     }
    
//     int move(int row, int col, int player) {
        
//     }
// };

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

/*
class TicTacToe {
public:
    TicTacToe(int n): n(n) {
        grid = vector<vector<int>>(n, vector(n, 0));
    }
    
    int move(int row, int col, int player) {
        grid[row][col] = player;
        
//         for (auto row: grid) {
//             for(auto item: row)
//                 cout<<item<<" ";
//             cout<<endl;
//         }
//         cout<<endl;
        
        if (checkRow(row, player) 
            || checkCol(col, player) 
            || ( row == col && checkDiag(player)) 
            || ( row == n - col - 1 && checkAntiDiag(player)) ) return player;
        return 0;
    }
private:
    vector<vector<int>> grid;
    int n;
    
    bool checkRow(int row, int player) {
        for(int col = 0; col < n; col++) if (grid[row][col] != player) return false;
        return true;
    }
    
    bool checkCol(int col, int player) {
        for(int row = 0; row < n; row++) if (grid[row][col] != player) return false;
        return true;
    }
    
    bool checkDiag(int player) {
        for(int i = 0; i < n; i++) if (grid[i][i] != player) return false;
        return true;
    }
    
     bool checkAntiDiag(int player) {
        for(int i = 0; i < n; i++) if (grid[i][n-i-1] != player) return false;
        return true;
    }
};
*/

class TicTacToe {
public:
    TicTacToe(int n): n(n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diag = 0;
        antiDiag = 0;
    }
    
    int move(int row, int col, int player) {
        auto marker = (player == 1) ? 1: -1;
        rows[row] += marker;
        cols[col] += marker;
        if (row == col) diag += marker;
        if (row == n - col - 1) antiDiag += marker;
        
        auto c = [&](int num) { return abs(num) == n; };
        if (c(rows[row]) || c(cols[col]) || c(diag) || c(antiDiag)) 
            return player;
        return 0;
    }
private:
    vector<int> rows, cols;
    int diag;
    int antiDiag;
    int n;
};