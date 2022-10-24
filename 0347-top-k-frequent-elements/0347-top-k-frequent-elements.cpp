class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (auto num: nums) counter[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto [key, frequency]: counter) {
            pq.push({frequency, key});
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while(pq.size()) {
            auto elem = pq.top(); pq.pop();
            res.push_back(elem.second);
        }
        return res;
    }
};