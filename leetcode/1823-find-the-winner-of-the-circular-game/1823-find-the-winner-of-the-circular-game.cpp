class Solution {
public:
    int findTheWinner(int n, int k) {        
        queue<int> q;
        for (auto i = 1; i <= n; i++) q.push(i);
            
        while (q.size() != 1) {
            auto x = k;
            while (x > 1) {
                auto elem = q.front(); q.pop();
                q.push(elem);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
};