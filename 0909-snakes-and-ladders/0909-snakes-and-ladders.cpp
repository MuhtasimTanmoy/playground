class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(); int steps = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        queue<int> q; q.push(1);
        visited[n - 1][0] = true;
        
        while (q.size()) {
            auto sz = q.size();
            while (sz--) {
                auto curr = q.front(); q.pop();
                if (curr == n * n) return steps;
                
                for (auto i = 1; i <= 6; i++) {
                    auto next = curr + i;
                    if (next > n * n) break;
                    
                    auto r = n - (next - 1) / n - 1, c = (next - 1) % n;
                    if (r % 2 == n % 2) c = n - c - 1;
                    
                    if (visited[r][c] == false) {
                        visited[r][c] = true;
                        auto toBeNext = (board[r][c] == -1 ? next: board[r][c] );
                        q.push(toBeNext);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};