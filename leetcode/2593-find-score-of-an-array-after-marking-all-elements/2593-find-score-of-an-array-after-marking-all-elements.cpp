class Solution {
public:
     long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) pq.push({nums[i], i});

        auto mark = [&](int idx) {
            nums[idx] = 0;
            auto prev = idx - 1, next = idx + 1;
            if (prev >= 0) nums[prev] = 0;
            if (next < nums.size()) nums[next] = 0;
        };

        long long res = 0;
        while (pq.size()) {
            auto top = pq.top(); pq.pop();
            auto val = top.first, idx = top.second;
            if (nums[idx]) res += nums[idx], mark(idx);
        }
        return res;
    }
};