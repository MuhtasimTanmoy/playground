class Solution {
    bool find(int num, vector<int>& aliceSizes) {
            int left = 0;
            int right = size(aliceSizes) - 1;
            while (left <= right) {
                auto mid = left + (right - left) / 2;
                auto now = aliceSizes[mid];
                if (now == num) return true;
                else if (now > num) right = mid - 1;
                else left = mid + 1;
            }
            return false;
        };
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        auto aSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        auto bSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        auto delta = ( bSum - aSum ) >> 1;
        if (delta < 0) swap(aSum, bSum);
        sort(aliceSizes.begin(), aliceSizes.end());
        for (auto b: bobSizes) {
            auto target = b - delta;
            if (find(target, aliceSizes)) return { b - delta, b };
        }
        return {-1, -1};
    }
};