/*
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops, int res = 0) {
        vector<int> rows(n + 1, 0), cols(m + 1, 0);
        for (auto op: ops) {
            auto x = op[0], y = op[1];
            rows[0]++; rows[y]--;
            cols[0]++; cols[x]--;
        }
        
        int inRow = 0, inCol = 0;
        for (auto i = 0, calc = 0; i < rows.size() - 1; i++) {
            calc += rows[i];
            res = max(res, calc);
            if (res == calc) inRow++;
        }
        for (auto i = 0, calc = 0; i < cols.size() - 1; i++) {
            calc += cols[i];
            res = max(res, calc);
            if (res == calc) inCol++;
        }
        return inRow * inCol;
    }
};
*/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int inRow = n, inCol = m;
        for (auto op: ops) {
            auto x = op[0], y = op[1];
            inRow = min(inRow, y);
            inCol = min(inCol, x);
        }
        return inRow * inCol;
    }
};