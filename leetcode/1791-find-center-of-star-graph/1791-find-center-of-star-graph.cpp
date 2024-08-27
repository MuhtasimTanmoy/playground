class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> C;
        for (auto edge: edges) {
            auto from = edge.front(), back = edge.back();
            C[from]++, C[back]++;
            if (C[from] == n) return from;
            if (C[back] == n) return back;
        }
        throw "error";
    }
};