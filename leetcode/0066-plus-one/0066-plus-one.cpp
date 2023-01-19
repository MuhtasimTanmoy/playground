class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto remain = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if ((digits[i] + remain) > 9) digits[i] = 0;
            else if (remain) { digits[i]++, remain = 0; }
        }
        if (remain) digits.insert(digits.begin(), remain);
        return digits;
    }
};