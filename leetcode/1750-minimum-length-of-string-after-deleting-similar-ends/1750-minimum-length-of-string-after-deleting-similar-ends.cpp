class Solution {
public:
    int minimumLength(string s) {
        deque<char> d(s.begin(), s.end());
        while (d.size() > 1) {
            auto l = d.front(), r = d.back();
            if (l == r) {
                auto now = l;
                while (d.size() && now == d.front()) d.pop_front();
                while (d.size() && now == d.back()) d.pop_back();
            } else break;
        }
        return d.size();
    }
};