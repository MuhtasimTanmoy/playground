class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        vector<vector<int>> res;
        function<void(int, vector<int>&)> go = [&](auto index, auto list) {
            auto canGoTo = graph[index];
            for (auto item: canGoTo) {
                list.push_back(item);
                if (item == n) res.push_back(list);
                go(item, list);
                list.pop_back();
            }
        };
        vector<int> cache{0};
        go(0, cache);
        return res;
    }
};