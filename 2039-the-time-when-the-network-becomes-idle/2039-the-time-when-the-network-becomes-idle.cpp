class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        bool visited[100001] = {true};
        vector<vector<int>> al(pat.size());
        for (auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        int res = 0;
        vector<int> q{0};
        for (int cnt = 1; !q.empty(); ++cnt) {
            vector<int> q1;
            for (int i : q) {
                for (int j : al[i])
                    if (!visited[j]) {
                        visited[j] = true;
                        res = max(res, cnt * 2 + (cnt * 2 - 1) / pat[j] * pat[j]);                    
                        q1.push_back(j);
                    }
            }
            swap(q, q1);
        }
        return res + 1;
    }
};