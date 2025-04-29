class Solution {
public:
    int numberOfComponents(vector<vector<int>>& P, int k) {
        int len = P.size();
        for (auto &p: P) {
            auto s = set<int>(p.begin(), p.end());
            p = vector<int>(s.begin(), s.end());
        }

        auto match = [](vector<int>& l, vector<int>& r) {
            int m = 0;
            for (auto i = 0, j = 0; i < l.size(); i++) {
                while (j < r.size() && r[j] < l[i]) j++;
                if (j == r.size()) break;
                if (l[i] == r[j]) m++;
            }
            return m;
        };

        vector<vector<int>> v(len, vector<int>{});
        for (auto i = 0; i < P.size() - 1; i++)
            for (auto j = i + 1; j < P.size(); j++) {
                auto m = match(P[i], P[j]);
                if (m >= k) 
                    v[i].push_back(j),
                    v[j].push_back(i);
            }

        set<int> visisted;
        function<void(int)> go = [&](int i) {
            visisted.insert(i);
            for (auto to: v[i]) {
                if (visisted.count(to)) continue;
                go(to);
            }
        };
        
        int component = 0;
        for (auto i = 0; i < len; i++) {
            if (visisted.count(i)) continue;
            component++;
            go(i);
        }
        return component;
    }
};