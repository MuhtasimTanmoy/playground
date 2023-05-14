class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, counter = 1, len = n * n;
        pair<int, int> pos = {0, 0};
        
        while (len--) {
            res[pos.first][pos.second] = counter++;
            pair<int, int> to = { 
                pos.first + dirs[d].first, 
                pos.second + dirs[d].second 
            };
            
            if (to.first < 0
                || to.second < 0
                || to.first == n
                || to.second == n
                || res[to.first][to.second]) {
                    d = ( d + 1 ) % 4;
                    pos = { pos.first + dirs[d].first, pos.second + dirs[d].second };
            } else
                pos = to;
        }
        return res;
    }
};