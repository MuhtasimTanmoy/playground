class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        unordered_map<string, int> row;
        for (auto r: g) {
            string builder = "";
            for (auto c: r) builder += to_string(c) + "-";
            row[builder]++;
        }
        int res = 0;
        for (int i = 0; i < g.size(); i++) {
            string builder = "";
            for (int j = 0; j < g[i].size(); j++) 
                builder += to_string(g[j][i]) + "-";
            if (row.count(builder))
                res += row[builder];
        }
        return res;
    }
};