class Solution {
public:
    // failed attempt
    /*
    int longestCycle(vector<int>& e, int res = -1) {
        unordered_map<int, int> visited;
        for (int i = 0; i < e.size(); ++i) {
            for (int start = i, cnt = 0; start != -1; start = e[start], cnt++) 
                if (visited.count(start)) {
                    res = max(res, cnt - visited[start]);
                    break;
                } else visited[start] = cnt;
        }
        return res;
    }
    */
    
    int longestCycle(vector<int>& e) {
        int res = -1;
        vector<pair<int, int>> memo(e.size(), {-1, -1});
        for (int i = 0; i < e.size(); ++i)
            for (int j = i, dist = 0; j != -1; j = e[j], dist++) {
                auto [dist_i, from_i] = memo[j];
                if (dist_i == -1) memo[j] = {dist, i};
                else {
                    if (from_i == i) res = max(res, dist - dist_i);
                    break;
                }
            }
        return res;
    }
};