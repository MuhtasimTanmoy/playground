class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto &grid = board;
        unordered_set<string> bag;
        for(int i = 0; i < size(grid); i++) {
            for(int j = 0; j < size(grid[0]); j++) {
                
                auto curr = grid[i][j];
                if (curr == '.') continue;
                
                auto rowMark = "r" + to_string(j) + curr;
                auto colMark = "c" + to_string(i) + curr;
                auto gridMark = "g" + to_string(i/3) + to_string(j/3) + curr;
                
                if (bag.count(rowMark) || bag.count(colMark) || bag.count(gridMark)) return false;
                
                bag.insert(rowMark);
                bag.insert(colMark);
                bag.insert(gridMark);
            }
        }

        return true;
    }
};