class Solution {
public:
    bool checkOnesSegment(string s) {
        int left = 0, right = size(s) - 1;
        
        while(left < size(s) && s[left++] == '0'){}
        while(right >= 0 && s[right--] == '0'){}
        
        while(left < right) 
            if (s[left] != '1' || s[left++] != s[right--]) return false;
        
        return true;
    }
};