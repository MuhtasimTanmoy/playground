// GETS TLE
/*
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, 
                                           vector<vector<int>>& edges,
                                           vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<int, int>>> g;
        for (auto edge: edges) {
            auto from = edge[0], to = edge[1], cost = edge[2];
            g[from].emplace_back(to, cost),
            g[to].emplace_back(from, cost);
        }
        
        vector<bool> visited(n, false);
        function<bool(int, int, int)> go = [&](auto from, auto to, auto limit) {
            if (visited[from]) return false;
            if (from == to) return true;
            visited[from] = true;
            for (auto dests: g[from]) {
                auto dest = dests.first, weight = dests.second;
                if (weight >= limit) continue;
                if (go(dest, to, limit)) return true;
            }
            return false;
        };
        
        vector<bool> res;
        for (auto query: queries) {
            auto from = query[0], to = query[1], limit = query[2];
            visited = vector<bool>(n, false);
            auto is_possible = go(from, to, limit);
            res.push_back(is_possible);
        }
        return res;
    }
};
*/

static class DSU {
    vector<int> Parent, Rank;
    
    public:
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, 
                                           vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        DSU dsu(n);
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
		
        sort(queries.begin(), queries.end(), 
             [](auto &l, auto &r) { return l[2] < r[2]; });
        sort(edgeList.begin(), edgeList.end(), 
             [](auto &l, auto &r) { return l.back() < r.back(); });
		
        int i = 0;
        vector<bool> result(queries.size());
        for (vector<int> &q:queries) {
            while (i < edgeList.size() && edgeList[i][2] < q[2]) 
                dsu.Union(edgeList[i][0],edgeList[i++][1]);
            result[q.back()] = dsu.Find(q[0]) == dsu.Find(q[1]);
        }
        return result;
    }
};