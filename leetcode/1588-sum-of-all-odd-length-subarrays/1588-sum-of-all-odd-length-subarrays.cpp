class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for (auto i = 0; i < arr.size(); i++) {
            auto localSum = 0;
            for (auto j = i; j < arr.size(); j++) {
                localSum += arr[j];
                if ((j - i + 1) & 1) sum += localSum;
            }
        }
        return sum;
    }
};