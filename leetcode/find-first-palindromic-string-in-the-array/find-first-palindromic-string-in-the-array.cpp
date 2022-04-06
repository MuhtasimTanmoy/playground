class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        auto isPalindrome = [](string& a) -> bool {
            int left = 0;
            int right = size(a) - 1;
            
            while (left < right) {
                if ( a[left++] != a[right--] ) { return false; }
            }
            
            return true;
        };
        
        for (auto s: words) {
            if ( isPalindrome(s) ) { return s; }
        }
        
        return "";
        
    }
};