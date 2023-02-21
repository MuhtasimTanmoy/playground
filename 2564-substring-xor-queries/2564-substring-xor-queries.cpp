class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> m;
        vector<vector<int>> res;
        for (int i = 0; i < s.size(); ++i) {
            long long val = 0;
            for (int j = i; j < min(i + 30, (int)s.size()); ++j) {
                val = (val << 1) + (s[j] == '1');
                if (m.count(val) == 0) m[val] = {i, j};
                if (s[i] == '0') break;
            }
        }
        for (const auto &q : queries)
            if (auto it = m.find(q[0] ^ q[1]); it != end(m)) res.push_back(it->second);
            else res.push_back({-1, -1});
        return res;
    }
};