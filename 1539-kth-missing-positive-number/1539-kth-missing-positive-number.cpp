class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = k;
        for (auto a: arr) if (a <= ans) ans++; else break;
        return ans;
    }
};