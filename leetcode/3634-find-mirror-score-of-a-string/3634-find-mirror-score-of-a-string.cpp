class Solution {
public:
    long long calculateScore(string s) {
        auto mirror = [](auto c) -> char {
            auto i = c - 'a';
            return 'a' + (25 - i);
        };
        long long res = 0;
        unordered_map<char, vector<int>> m;
        for (auto i = 0; i < s.size(); i++) {
            auto find = mirror(s[i]);
            if (m.count(find)) {
                auto to_mark = m[find].back();
                m[find].pop_back();
                if (m[find].empty()) m.erase(find);
                res += i - to_mark;
            } else
                m[s[i]].push_back(i);
        }
        return res;
    }
};