class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = k;
        for (auto item: arr) { if (ans < item) break; ans++; }
        return ans;
    }
};