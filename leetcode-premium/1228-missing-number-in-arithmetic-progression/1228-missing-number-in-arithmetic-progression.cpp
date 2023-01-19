class Solution {
public:
    int missingNumber(vector<int>& arr) {
        auto distance = (arr.back() - arr.front()) / (int) arr.size();
        for (int i = 1; i < arr.size(); i++)
            if ((arr[i] - arr[i-1]) != distance)
                return arr[i-1] + distance;
        return arr.front();
    }
};