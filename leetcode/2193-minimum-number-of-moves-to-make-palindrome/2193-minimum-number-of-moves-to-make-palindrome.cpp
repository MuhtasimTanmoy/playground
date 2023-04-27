class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0;
        while (s.size()) {
            auto i = s.find(s.back());
            if (i == s.size() - 1) res += i / 2;
            else res += i, s.erase(i, 1);
            s.pop_back();
        }
        return res;
    }
};