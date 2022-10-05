class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = size(digits);
        int rem = 1;
        for (int i = n - 1; i >= 0; i--) {
            auto addition = digits[i] + rem;
            digits[i] = addition % 10;
            rem = (addition > 9) ? 1 : 0; 
        }
        if (rem) digits.insert(digits.begin(), rem);
        return digits;
    }
};