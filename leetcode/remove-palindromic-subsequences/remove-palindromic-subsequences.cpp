class Solution {
public:
    int removePalindromeSub(string s) {
        
        auto isPalindrome = [&]() -> bool {
            int left = 0;
            int right = size(s) - 1;
            
            while( left < right ) {
                if ( s[left++] != s[right--] ) return false;
            }
            
            return true;
        };
        
        return isPalindrome() ? 1 : 2;
    }
};