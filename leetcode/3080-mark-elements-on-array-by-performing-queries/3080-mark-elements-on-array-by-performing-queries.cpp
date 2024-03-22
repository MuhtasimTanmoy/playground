class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& qs) {
        long long sum = 0;
        unordered_set<int> marked;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (auto i = 0; i < nums.size(); i++) pq.push({nums[i], i}), sum += nums[i];
        vector<long long> res;
        for (auto q: qs) {
            auto index = q.front(), mark_left = q[1];
            
            if (!marked.count(index)) 
                marked.insert(index),
                sum -= nums[index];
            
            while (pq.size() && mark_left) {
                auto [val, idx] = pq.top(); pq.pop();
                if (!marked.count(idx)) 
                    mark_left--, 
                    sum -= val,
                    marked.insert(idx);
            }
            res.push_back(sum);
        }
        return res;
    }
};