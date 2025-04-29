class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& P, string s) {
        vector<vector<string>> res;
        sort(P.begin(), P.end());

        string search_for = "";
        for (auto c: s) {
            search_for += c;
            auto it = lower_bound(P.begin(), P.end(), search_for);
            int len = it - P.begin();

            res.push_back({});
            for (auto now = len; now < min(len + 3, (int) P.size()); now++) {
                if (P[now].find(search_for) == 0)
                    res.back().push_back(P[now]);
            }
        }
        return res;
    }
};