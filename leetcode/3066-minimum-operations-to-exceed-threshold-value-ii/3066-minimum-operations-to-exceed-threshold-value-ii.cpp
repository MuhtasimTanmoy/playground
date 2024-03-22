class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        priority_queue<long long, 
                       vector<long long>, 
                       greater<long long>> pq(nums.begin(), nums.end());
        while (pq.size() > 1) {
            auto one = pq.top(); pq.pop();
            if (one >= k) break;
            res++;
            auto two = pq.top(); pq.pop();
            auto compute = min(one, two) * 2 + max(one, two);
            pq.push(compute);
        }
        return res;
    }
};