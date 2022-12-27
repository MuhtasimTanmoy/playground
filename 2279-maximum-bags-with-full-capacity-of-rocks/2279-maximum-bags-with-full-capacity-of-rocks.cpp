class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        vector<int> count;
        int n = rocks.size(), i;
        for (int i = 0; i < n; ++i) count.push_back(capacity[i] - rocks[i]);
        sort(count.begin(), count.end());
        for (i = 0; i < n && k >= count[i]; ++i) k -= count[i];
        return i;
    }
};