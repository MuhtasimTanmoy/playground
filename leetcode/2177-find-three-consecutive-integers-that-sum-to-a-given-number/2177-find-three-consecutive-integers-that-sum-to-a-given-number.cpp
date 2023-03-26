class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3) return {};
        auto mid = num / 3;
        return {mid - 1, mid, mid + 1};
    }
};