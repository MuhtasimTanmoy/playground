class Solution {
public:
    int maximum69Number (int num) {
        auto numStr = to_string(num);
        for (auto &c: numStr) if (c - '0' == 6) { c = '9'; break; }
        return stoi(numStr);
    }
};