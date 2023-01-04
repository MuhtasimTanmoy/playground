class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        auto hasZero = [](int num) {
            auto s = to_string(num);
            for (auto c: s) if (c == '0') return true;
            return false;
        };
        
        for (int i = 1; i < n; i++) {
            auto other = n - i;
            if (!hasZero(other) && !hasZero(i)) return {i, other};
        }
        
        throw "Error";
    }
};