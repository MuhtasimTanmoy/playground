class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>> pq;
        
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        
        int prev = INT_MIN, count = 1;
        for (auto num: nums) {
            if ( num != prev && prev != INT_MIN ) {
                pq.push({count, prev});
                if (pq.size() > k) pq.pop();
            }
            count = num == prev ? count + 1: 1;
            prev = num;
        }
        
        vector<int> res;
        while (pq.size()) 
            res.push_back(pq.top().second),
            pq.pop();
        return res;
    }
};