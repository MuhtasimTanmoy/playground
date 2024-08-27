class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto i = 0; i < nums.size(); i++) pq.push({nums[i], i});
        while (k--) {
            auto [val, index] = pq.top(); pq.pop();
            nums[index] *= multi;
            pq.push({nums[index], index});
        }
        return nums;
    }
};