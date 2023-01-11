class Solution {
    bool check(int tar, vector<int>& price, int k) {
        int count = 1;
        for (int i = 1, j = 0; i < price.size(); i++)
            if (price[i] - price[j] >= tar)
                j = i, count++;
        return count >= k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        auto left = 0, right = (int) price.back() - price.front() + 1;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (check(mid, price, k)) left = mid + 1; 
            else right = mid;
        }
        return left - 1;
    }
};