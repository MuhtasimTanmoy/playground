// class Solution {
// public:
//     int minTaps(int n, vector<int>& ranges) {
        
//         vector<pair<int, int>> r;
//         for (int i = 0; i < ranges.size(); i++) 
//             r.emplace_back(i - ranges[i], i + ranges[i]);
//         sort(r.begin(), r.end(), [](auto l, auto r) { return l.first < r.first; });
        
//         unordered_map<string, long long> dp;
//         auto gen_key = [](int a, int b) { return to_string(a) + "-" + to_string(b); };
        
//         function<long long(int, int)> go = [&](auto i, auto upto) {
//             if (upto >= n) return 0LL;
//             if (i == r.size()) return (long long) INT_MAX;
            
//             auto key = gen_key(i, upto);
//             if (dp.count(key)) return dp[key];
            
//             auto [from, to] = r[i];
//             if (from > upto) return (long long) INT_MAX;
            
//             auto next = lower_bound(r.begin(), r.end(), make_pair(to, 0), [](auto l, auto r) {
//                 return l.first < r.first;             
//             }) - r.begin();
            
//             if (next == r.end()) return 1;
//             if (next < n && r[next].first > to) next--;
//             cout<<next<<endl;
//             auto take = 1 + go(next, to), not_take = go(i + 1, upto);
//             return dp[key] = min(take, not_take);
//         };
        
//         auto res = go(0, 0);
//         return res == INT_MAX ? -1: res;
//     }
// };


class Solution {
public:
     int minTaps(int n, vector<int>& r) {
        vector<int> jumps(n + 1, 0);
        for (auto i = 0; i < r.size(); i++) {
            auto l = max(0, i - r[i]), e = min(n, i + r[i]);
            jumps[l] = max(jumps[l], e - l);
        }
        auto count = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < jumps.size() - 1; i++) {
            if (i > curFarthest) return -1;
            curFarthest = max(curFarthest, i + jumps[i]);
            if (i == curEnd) count++, curEnd = curFarthest;
        }
        return curFarthest >= n ? count : -1;
    }
};