// GETS TLE
// class Solution {
// public:
//     int twoCitySchedCost(vector<vector<int>>& costs) {
//         auto total = costs.size() / 2;
//         function<int(int, int, int)> go = [&](auto idx, auto a_cnt, auto b_cnt) {
//             if (idx == total * 2) return 0;
//             auto cost_a = costs[idx][0], cost_b = costs[idx][1];
//             auto take_a = a_cnt < total ? cost_a + go(idx + 1, a_cnt + 1, b_cnt): INT_MAX;
//             auto take_b = b_cnt < total ? cost_b + go(idx + 1, a_cnt, b_cnt + 1): INT_MAX;
//             return min(take_a, take_b);
//         };
//         return go(0, 0, 0);
//     }
// };

// class Solution {
// public:
//     int twoCitySchedCost(vector<vector<int>>& costs) {
//         auto total = costs.size() / 2;
//         unordered_map<string, int> key_store;
//         auto gen_key = [](int a, int b, int c) {
//             return to_string(a) + to_string(b) + to_string(c);
//         };
//         function<int(int, int, int)> go = [&](auto idx, auto a_cnt, auto b_cnt) {
//             if (idx == total * 2) return 0;
            
//             auto key = gen_key(idx, a_cnt, b_cnt);
//             if (key_store.count(key)) return key_store[key];
            
//             auto cost_a = costs[idx][0], cost_b = costs[idx][1];
//             auto take_a = a_cnt < total ? cost_a + go(idx + 1, a_cnt + 1, b_cnt): INT_MAX;
//             auto take_b = b_cnt < total ? cost_b + go(idx + 1, a_cnt, b_cnt + 1): INT_MAX;
//             return key_store[key] = min(take_a, take_b);
//         };
//         return go(0, 0, 0);
//     }
// };

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto a, auto b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int res = 0, cnt = 0;
        for (auto cost: costs) 
            res += cnt++ < costs.size() / 2 ? cost[0]: cost[1];
        return res;
    }
};