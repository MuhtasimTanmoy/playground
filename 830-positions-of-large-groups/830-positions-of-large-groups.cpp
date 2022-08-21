class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        char prev = '0';
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != prev) {
                prev = s[i];
                if (end - start >= 3) res.push_back({start, end - 1});
                start = i;
            }
            end++;
        }
        if (end - start >= 3) res.push_back({start, end - 1});
        return res;
    }
};