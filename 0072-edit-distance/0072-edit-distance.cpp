/*
class Solution {
public:
    int minDistance(string l, string r) {
        auto key = [&](int i, int j) { return to_string(i) + "-" + to_string(j); };
        unordered_map<string, int> cache;
        function<int(int, int)> go = [&](auto i, auto j) {
            if (i == 0) return j;
            if (j == 0) return i;
            auto k = key(i, j);
            if (cache.count(k)) return cache[k];
            if (l[i-1] == r[j-1]) return cache[k] = go(i-1, j-1);
            else {
                auto insert = go(i, j - 1), del = go(i - 1, j), repl = go(i-1, j-1);
                return cache[k] = min({repl, insert, del}) + 1;
            }
        };
        return go(l.size(), r.size());
    }
};


class Solution {
public:
    int minDistance(string l, string r) {
        vector<int> curr(r.size() + 1, 1); curr[0] = 0;
        for (auto i = 1; i <= l.size(); i++) {
            auto prev {curr};
            curr[0]++;
            for (auto j = 1; j <= r.size(); j++) {
                auto a = (int)(l[i-1] != r[j-1]) + prev[j - 1],
                     b = 1 + prev[j], 
                     c = 1 + curr[j-1];
                curr[j] = min({a, b, c});
            }
        }
        return curr[r.size()];      
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    int minDistance(string s, string t) {
        int M = s.size(),
            N = t.size();
        VI cur(N + 1);
        for (auto j{ 1 }; j <= N; ++j) cur[j] = 1 + cur[j - 1];
        for (auto i{ 1 }; i <= M; ++i) {
            auto pre{ cur };
            ++cur[0];
            for (auto j{ 1 }; j <= N; ++j) {
                auto a = int(s[i - 1] != t[j - 1]) + pre[j - 1],
                     b = 1 + pre[j],
                     c = 1 + cur[j - 1];
                cur[j] = min({ a, b, c });
            }
        }
        return cur[N];
    }
};