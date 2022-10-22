// class Solution {
// public:
//     int numberOfNodes(int n, vector<int>& queries) {
//         int ones = 0;
//         vector<int> list(n + 1, 0);
//         for (auto query: queries) {
//             queue<int> q; q.push(query);
//             while(q.size()) {
//                 auto elem = q.front(); q.pop();
//                 list[elem] = 1 - list[elem];
//                 if ( 2 * elem <= n ) q.push(2 * elem);
//                 if ( (2 * elem + 1) <= n ) q.push(2 * elem + 1);
//             }
//         }
//         for (auto elem: list) if (elem) ones++;
//         return ones;
//     }
// };

class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> f(n + 1);
        for (auto q : queries) f[q] ^= 1;
        function<int(int, int)> dfs = [&](int u, int v) {
            if (u > n) return 0;
            v ^= f[u];
            return v + dfs(u * 2, v) + dfs(u * 2 + 1, v);
        };
        return dfs(1, 0);
    }
};