class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int index = 0;
        
        for(auto tChar: t) {
            if ( tChar == s[index] ) {
                index++;
            }
        }
        
        return index == s.size();
    }
};