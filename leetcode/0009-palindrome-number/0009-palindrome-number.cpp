/*
class Solution {
public:
    bool isPalindrome(int x) {
        auto xStr = to_string(x);
        int left = 0, right = xStr.size() - 1;
        while (left < right) 
            if (xStr[left++] != xStr[right--]) 
                return false;
        return true;
    }
};
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long reverse = 0, cache = x;
        while (x) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse == cache;
    }
};