class Solution {
    bool isPalindrome(string& s) {
        int left = 0;
        int right = size(s) - 1;
        while(left < right) if (s[left++] != s[right--]) return false;
        return true;
    }
public:
    int removePalindromeSub(string s) {
        return isPalindrome(s) ? 1 : 2;
    }
};