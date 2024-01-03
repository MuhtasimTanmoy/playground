class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, 
                                          vector<int>& values) {
        unordered_map<int, vector<int>> mp;
        for (auto e: edges) 
            mp[e.front()].push_back(e.back()), 
            mp[e.back()].push_back(e.front());
        
        function<long long(int, int)> go = [&](auto now, auto parent) {
            long long val = values[now], sum = 0;
            for (auto to: mp[now]) 
                if (to != parent)
                    sum += go(to, now);
            return min(sum ? sum: INT_MAX, val);
        };
        
        long long deduct = go(0, -1), 
                  sum = accumulate(values.begin(), values.end(), 0LL);
        return sum - deduct;
    }
};