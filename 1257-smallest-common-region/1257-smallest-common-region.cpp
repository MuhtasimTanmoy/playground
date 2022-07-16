class Solution {
    string traverse(unordered_map<string, vector<string>>& graph,
                    string& now,
                    string& region1, 
                    string& region2) {
        if (now == region1 || now == region2) return now;
        int count = 0;
        string retStr = "";
        auto childs = graph[now];
        for(auto child: childs) {
            auto ret = traverse(graph, child, region1, region2);
            if (ret.size()) retStr = ret;
            if (ret == region1 || ret == region2) count++;
        }
        if (count == 2) return now;
        else return retStr;
    }
public:
    string findSmallestRegion(vector<vector<string>>& regions, 
                              string region1, string region2) {
        unordered_map<string, vector<string>> graph;
        for(auto region: regions)
            for(int i = 1; i < size(region); i++) 
                graph[region[0]].push_back(region[i]);
        return traverse(graph, regions[0][0], region1, region2);
    }
};