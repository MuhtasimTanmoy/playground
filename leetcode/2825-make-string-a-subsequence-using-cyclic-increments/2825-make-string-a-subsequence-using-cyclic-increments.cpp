class Solution {
public:
    bool canMakeSubsequence(string from, string to) {
        int i = 0;
        auto convert = [](char c) -> char {
            if (c == 'z') return 'a';
            return c + 1;
        };
        for (auto c: from) {
            if (c == to[i] || convert(c) == to[i]) i++;
            if (i == to.size())
                return true;
        }
        return false;
    }
};