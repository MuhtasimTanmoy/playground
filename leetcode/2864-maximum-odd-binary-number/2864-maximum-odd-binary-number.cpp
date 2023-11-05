class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int ones = count(begin(s), end(s), '1');
        return string(ones - 1, '1') + string(size(s) - ones, '0') + "1";
    }
};