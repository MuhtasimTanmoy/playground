class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        auto cnt = arr.size() / 4;
        for (auto i = 1, count = 1; i < arr.size(); i++) {
            if (arr[i-1] == arr[i]) count++; else count = 1;
            if (count > cnt) return arr[i];
        }
        return arr.front();
    }
};