// class Solution {
//     int MOD = 1e9 + 7;
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         vector<int> counter;
//         for (int i = 0; i < nums.size(); i++) {
//             int sum = 0;
//             for (int j = i; j < nums.size(); j++)
//                 sum += nums[j],
//                 counter.push_back(sum);
//         }
//         sort(counter.begin(), counter.end());
//         int res = 0;
//         for (int i = left - 1; i < right; i++)
//             res = (res + counter[i]) % MOD;
//         return res;
//     }
// };

class Solution {
    int MOD = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto i = 0; i < nums.size(); i++) pq.emplace(nums[i], i + 1);
        int res = 0;
        for (int i = 1; i <= right; i++) {
            auto elem = pq.top(); pq.pop();
            if (i >= left) res = (res + elem.first) % MOD;
            if (elem.second < n) 
                elem.first += nums[elem.second++],
                pq.emplace(elem.first, elem.second);
        }
        return res;
    }
};