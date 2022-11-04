class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> counter;
        for (auto edge: edges) {
            auto from = edge[0], to = edge[1];
            if (++counter[from] > 1) return from;
            if (++counter[to] > 1) return to;
        }
        throw "INVALID_INPUT";
    }
};