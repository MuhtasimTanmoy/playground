class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> temp;
        for (int i = 0; i < g.size(); i++) {
            auto item = g[i];
            temp[item].push_back(i);
            if (temp[item].size() == item)
                res.push_back(temp[item]),
                temp.erase(item);
        }
        return res;
    }
};