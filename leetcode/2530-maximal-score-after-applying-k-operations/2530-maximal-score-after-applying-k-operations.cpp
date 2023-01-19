class Solution {
public:
    long long maxKelements(vector<int>& nums, int k, long score = 0) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while (k--) {
            auto top = pq.top(); pq.pop();
            score += top;
            pq.push(ceil(top / 3.0));
        }
        return score;
    }
};