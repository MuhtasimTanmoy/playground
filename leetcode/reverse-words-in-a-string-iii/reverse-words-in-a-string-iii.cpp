class Solution {
public:
    string reverseWords(string s) {
        
        auto reverse = [&](int left, int right) {
            while(left < right) {
                auto c = s[left];
                s[left] = s[right];
                s[right] = c;
                left++;
                right--;
            }
        };
        
        
        int tokenBegin = 0;
        int tokenEnd = 0;
        
        while(tokenBegin < size(s)) {
            while(tokenEnd < size(s) && s[tokenEnd] != ' ') tokenEnd++;
            reverse(tokenBegin, tokenEnd - 1);
            tokenEnd++;
            tokenBegin = tokenEnd;
        }
        
        return s;
    }
};