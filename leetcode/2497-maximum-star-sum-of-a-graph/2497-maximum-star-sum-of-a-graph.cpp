class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int res = INT_MIN;
        vector<vector<int>> al(vals.size());
        for (auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < vals.size(); ++i) {
            sort(begin(al[i]), end(al[i]), [&](int a, int b){
               return  vals[a] > vals[b];
            });
            int res1 = vals[i];
            for (int j = 0; j < k && j < al[i].size() && vals[al[i][j]] > 0; ++j) 
                res1 += vals[al[i][j]];
            res = max(res, res1);
        }
        return res;
    }
};