class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        for(int i = 0; i + m < size(arr); i++) {
            if (arr[i] == arr[i + m]) {
                count++;
                if (count == m * (k - 1)) return true;
            } else count = 0;
        }
        return false;
    }
};