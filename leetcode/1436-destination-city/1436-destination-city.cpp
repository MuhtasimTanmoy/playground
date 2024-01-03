class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> outdegree, indegree;
        for (auto path: paths) {
            auto from = path.front(), to = path.back();
            outdegree[from]++;
            indegree[to]++;
        }
        for (auto [city, _]: indegree)
            if (!outdegree.count(city))
                return city;
        throw "error";
    }
};