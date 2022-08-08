class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        auto ok = [](auto x) { return 1 <= x && x <= 26; };
        unordered_map<int, int> bag;
        function<int(int)> go = [&](int index) {
            if (index == len) return 1;
            if (bag.count(index)) return bag[index];
            auto one = s[index] - '0';
            auto two = (one && (index + 1) < len) ? stoi(s.substr(index, 2)) : 0;
            return bag[index] = (ok(one) ? go(index+1): 0) + (ok(two) ? go(index+2): 0);
        };
        return go(0);
    }
};