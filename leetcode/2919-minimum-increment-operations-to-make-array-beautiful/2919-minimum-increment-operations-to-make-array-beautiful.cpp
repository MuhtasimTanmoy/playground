class Solution {
public:
    long long minIncrementOperations(vector<int>& n, int k) {
        deque<long long> dp(3);
        for (int i = 0; i < n.size(); ++i) {
            dp.push_back(max(0, k - n[i]) + *min_element(begin(dp), end(dp)));
            dp.pop_front();
        }
        return *min_element(begin(dp), end(dp));
    }
};