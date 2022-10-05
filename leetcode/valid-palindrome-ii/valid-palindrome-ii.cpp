class Solution {
public:
    
    bool isChanceValid = true;
    
    bool find(int l, int r, string& s) {
        while ( l < r ) {
            
            if(s[l] != s[r]) {
                
                if (isChanceValid) {
                    isChanceValid = false;
                    return find(l, r - 1, s) || find(l + 1, r, s);
                } else {
                    return false;
                }
            }
            
            l++;
            r--;
        } 
        return true;
    }
    
    bool validPalindrome(string s) {
        return find(0, size(s) -1, s);
    }
};