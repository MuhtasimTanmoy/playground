class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end()); nums.push_back(-1);
        priority_queue<pair<int, int>> pq;
        for (auto i = 1, count = 1; i < nums.size(); i++) 
            if (nums[i] != nums[i - 1])
                pq.push({nums[i - 1], count}), count = 1;
            else count++;
        int res = 0;
        while (pq.size() > 1) {
            auto [first, one] = pq.top(); pq.pop();
            auto [second, two] = pq.top(); pq.pop();
            res += one; pq.push({second, one + two});
        }
        return res;
    }
};