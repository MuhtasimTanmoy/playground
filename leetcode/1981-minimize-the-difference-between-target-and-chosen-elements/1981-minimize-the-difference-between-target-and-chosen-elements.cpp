// GOT TLE
/*
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        auto gen_key = [](auto l, auto ...r) { return (to_string(l) + ... + (to_string(r))); };
        unordered_map<string, int> c;
        function<int(int, int)> go = [&](auto i, auto sum) {
            if (i == mat.size()) return abs(target - sum);
            
            auto key = gen_key(i, sum);
            if (c.count(key)) return c[key];
            
            int res = INT_MAX;
            for (auto elem: us)
                res = min(res, go(i + 1, sum + elem));
            return c[key] = res;
        };
        return go(0, 0);
    }
};
*/

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<5000> p(1);
        for (auto& r : mat) {
            bitset<5000> tmp;
            for (auto& i : r) {
                tmp = tmp | (p << i);
            }
            swap(p,tmp);
        }
        int res = 10000;
        for (int i = 0; i < 5000; ++i) {
            if (p[i]) res = min(res, abs(i - target));
        }
        return res;
    }
};