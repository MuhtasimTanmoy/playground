class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = k;
        for (auto item: arr) { if (ans < item) return ans; ans++; }
        return ans;
    }
};