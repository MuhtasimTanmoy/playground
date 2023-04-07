
// TLE
/*
class Solution {
public:
    long long numberOfWays(string s) {
        auto gen_key = [](auto l, auto ... r) {
            return (to_string(l) + ... + ("-" + to_string(r)));
        };
        unordered_map<string, long long> um;
        function<long long(int, char, int)> go = [&](auto idx, char prev, int selected) {
            if (idx >= s.size()) return selected == 3 ? 1LL: 0;
            if (selected == 3) return 1LL;
            
            auto key = gen_key(idx, prev, selected);
            if (um.count(key)) return um[key];
            
            long long got = 0;
            if (s[idx] != prev) got += go(idx + 1, s[idx], selected + 1);
            got += go(idx + 1, prev, selected);
            return um[key] = got;
        };
        return go(0, 'r', 0);
    }
};
*/

class Solution {
public:
    long long numberOfWays(string &s, char firstLast) {
        long long first = 0, second = 0, comb = 0, res = 0;
        for (char ch : s)
            if (ch == firstLast) {
                comb += first * second;
                res += comb;
                second = 0;
                ++first;
            } else ++second;
        return res;
    }
    
    long long numberOfWays(string s) {
        return numberOfWays(s, '0') + numberOfWays(s, '1');
    }
};