class Solution {
public:
    string makeGood(string s) {
        string res; res += s.front();
        auto banned_distance = 'a' - 'A';
        for (auto i = 1; i < s.size(); i++) {
            auto distance = abs((res.size() ? res.back(): 0) - s[i]);
            if (distance != banned_distance) res += s[i]; else res.pop_back();
        }
        return res;
    }
};