class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            auto m = l + (r - l) / 2;
            if (arr[m - 1] < arr[m] && arr[m] > arr[m + 1])
                return m;
            else if (arr[m - 1] < arr[m] && arr[m] < arr[m + 1])
                l = m;
            else r = m;
        }
        return -1;
    }
};