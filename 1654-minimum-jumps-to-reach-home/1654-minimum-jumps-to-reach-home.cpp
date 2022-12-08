// class Solution {
// public:
//     int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
//         unordered_set<int> dont(forbidden.begin(), forbidden.end());
//         int ans = INT_MAX;
//         unordered_map<int, int> dp;
//         function<void(int pos, int count)> go = [&](int pos, int count) {
//             if (dp.count(pos)) {
//                 ans = min(ans, count);
//                 return;
//             }
//             if (dont.count(pos)) return;
//             if (pos < 0 || pos > x + b) return;
//             if (pos == x) ans = min(ans, count);
//             dp[pos] = ans;
//             go(pos + a, count + 1);
//             go(pos - b, count + 1);
//         };
//         go(0, 0);
//         return ans == INT_MAX? -1: ans;
//     }
// };

using tup = tuple<int, int, bool>; // location, count, previous_jump(forward or backward)
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<tup> que; // forward true
        set<pair<int, bool>> seen; //previous jump direction with its location
        que.push({0, 0, true});
        for (int i : forbidden) 
            seen.insert({i, true}), seen.insert({i, false});
        while (!que.empty()) {
            auto [loc, count, forward] = que.front();
            que.pop();
            if (loc == x) 
                return count;
            else if (seen.count({loc, forward}) || loc > 6000)
                continue;
            seen.insert({loc, forward});
            que.push({loc + a, count + 1, true});
            if (forward && loc >= b)
                que.push({loc - b, count + 1, false});
        }
        return -1;
    }
};