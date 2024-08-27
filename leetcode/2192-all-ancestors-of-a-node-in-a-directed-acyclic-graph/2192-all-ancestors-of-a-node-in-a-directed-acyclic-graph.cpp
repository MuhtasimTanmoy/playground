class Solution {
public:
    /*
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tracks(n, vector<int>());
        for (auto edge: edges) {
            auto from = edge.front(), to = edge.back();
            tracks[to].push_back(from);
        }
        for (auto &track: tracks) {
            set<int> all;
            for (auto i: track) {
                vector<int> now{i};
                while (now.size()) {
                    auto c = now.back();
                    all.insert(c);
                    now.pop_back();
                    for (auto p: tracks[c]) 
                        if (!all.count(p)) 
                            now.push_back(p);
                }
            }
            track = vector<int>(all.begin(), all.end());
            sort(track.begin(), track.end());
        }
        return tracks;
    }
    */
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), al(n);
        function<void(int, int)> dfs = [&](int i, int anc) {
            for (auto j : al[i])
                if (res[j].empty() || res[j].back() != anc) 
                    res[j].push_back(anc),
                    dfs(j, anc);    
        };
        for (auto &e: edges) al[e[0]].push_back(e[1]);
        for (int i = 0; i < n; ++i) dfs(i, i);
        return res;    
    }
};