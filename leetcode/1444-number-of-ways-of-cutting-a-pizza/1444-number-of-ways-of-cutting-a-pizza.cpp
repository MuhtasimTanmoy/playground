// Copied from solution, Couldn't solve.

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        
        vector apples(rows + 1, vector<int>(cols + 1));
        vector f(rows, vector<int>(cols));
        for (int row = rows - 1; row >= 0; row--) 
            for (int col = cols - 1; col >= 0; col--) {
                apples[row][col] = (pizza[row][col] == 'A') 
                                    + apples[row + 1][col] 
                                    + apples[row][col + 1] 
                                    - apples[row + 1][col + 1];
                f[row][col] = apples[row][col] > 0;
            }
        
        const int mod = 1000000007;
        for (int remain = 1; remain < k; remain++) {
            vector g(rows, vector<int>(cols));
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    for (int next_row = row + 1; next_row < rows; next_row++) {
                        if (apples[row][col] - apples[next_row][col] > 0) 
                            (g[row][col] += f[next_row][col]) %= mod;
                    }
                    for (int next_col = col + 1; next_col < cols; next_col++) {
                        if (apples[row][col] - apples[row][next_col] > 0)
                            (g[row][col] += f[row][next_col]) %= mod;
                    }
                }
            }
            f = g;
        }
        return f[0][0];
    }
};