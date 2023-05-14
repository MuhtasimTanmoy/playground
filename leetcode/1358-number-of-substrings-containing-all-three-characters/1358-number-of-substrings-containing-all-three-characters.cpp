class Solution {
public:
    int numberOfSubstrings(string s, int res = 0) {
        int n = s.size();
        vector<int> mapper(3, 0);
        auto all = [&]() {
            for (auto i: mapper) if (i == 0) return false;
            return true;
        };
        for (int l = 0, r = 0; r < n; r++) {
            auto idx = s[r] - 'a';
            mapper[idx]++;
            while (all())
                res += n - r,
                mapper[s[l++] - 'a']--;
        }
        return res;
    }
};