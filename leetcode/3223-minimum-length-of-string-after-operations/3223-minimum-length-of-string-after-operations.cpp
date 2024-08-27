class Solution {
public:
    int minimumLength(string s, int len = 0) {
        vector<int> li[26] = {};
        for (auto i = 0; i < s.size(); i++) li[s[i] - 'a'].push_back(i);
        for (auto l: li) if (l.size()) len += l.size() & 1 ? 1: 2;
        return len;
    }
};