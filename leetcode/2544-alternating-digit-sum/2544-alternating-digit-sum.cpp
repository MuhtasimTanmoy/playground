class Solution {
public:
    int alternateDigitSum(int n, bool isPos = true, int res = 0) {
        auto nStr = to_string(n);
        for (auto c: nStr) {
            auto val = c - '0';
            res += isPos ? val: -val;
            isPos = !isPos;
        }
        return res;
    }
};