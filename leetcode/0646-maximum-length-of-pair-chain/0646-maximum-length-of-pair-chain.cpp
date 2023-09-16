// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end(), [](auto l, auto r) {
//             return l.front() < r.front();
//         });
        
//         unordered_map<string, int> dp;
//         auto gen_key = [](auto a, auto b) {
//             return to_string(a) + "-" + to_string(b);
//         };
        
//         function<int(int, int)> go = [&](auto i, auto to) {
//             if (i == pairs.size()) return 0;
            
//             auto key = gen_key(i, to);
//             if (dp.count(key)) return dp[key];
            
//             auto from = pairs[i].front(), to_now = pairs[i].back();
//             auto res = go(i + 1, to);
//             if (from > to) res = max(res, 1 + go(i + 1, to_now));
//             return dp[key] = res;      
//         };
        
//         return go(0, -1001);
//     }
// };

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto l, auto r) {
            return l.back() < r.back();
        });
        int count = 0, left = -1001;
        for (auto pair: pairs) {
            auto l = pair.front(), r = pair.back();
            if (l > left) count++, left = r;
        }
        return count;
    }
};