class Solution {
public:
    int largestPathValue(string cs, vector<vector<int>>& edges) {
        vector<vector<int>> al(cs.size()), cnt(cs.size(), vector<int>(26));
        vector<int> indegrees(cs.size());
        for (auto &e: edges) {
            al[e[0]].push_back(e[1]);
            ++indegrees[e[1]];
        }
        vector<int> q;
        for (int i = 0; i < cs.size(); ++i)
            if (indegrees[i] == 0)
                q.push_back(i);
        int res = 0, processed = 0;
        while (q.size()) {
            vector<int> q1;
            for (auto i : q) {
                ++processed;
                res = max(res, ++cnt[i][cs[i] - 'a']);
                for (auto j : al[i]) {
                    for (auto k = 0; k < 26; ++k)
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    if (--indegrees[j] == 0)
                        q1.push_back(j);
                }
            }
            swap(q, q1);
        }
        return processed != cs.size() ? -1 : res;
    }
};