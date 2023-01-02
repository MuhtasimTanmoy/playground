class Solution {
public:
    string thousandSeparator(int n) {
        auto nStr = to_string(n); string res = "";
        for (int i = nStr.size() - 1; i >= 0; i--) {
            auto delimIndex = nStr.size() - i - 1;
            if (delimIndex && !(delimIndex % 3)) res = "." + res;
            res = nStr[i] + res;
        }
        return res;
    }
};