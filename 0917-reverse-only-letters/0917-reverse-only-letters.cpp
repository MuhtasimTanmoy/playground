class Solution {
public:
    string reverseOnlyLetters(string s) {
        auto left = 0, right = (int)s.size() - 1;
        while (left < right) {
            if (!isalpha(s[left])) left++;
            else if (!isalpha(s[right])) right--;
            else swap(s[left++], s[right--]);
        }
        return s;
    }
};