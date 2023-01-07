class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> res(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); i++) 
            if (colsum[i] == 2) {
                upper--, lower--;
                res[0][i] = 1;
                res[1][i] = 1;
            } else if (colsum[i] == 1) 
                if (lower < upper) {
                    upper--;
                    res[0][i] = 1;
                } else {
                    lower--;
                    res[1][i] = 1;
                }
        if (upper || lower) return {};
        return res;
    }
};