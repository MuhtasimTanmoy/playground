class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        bool s1 = count(s.begin(), s.end(), '1'), 
             t1 = count(t.begin(), t.end(), '1');
        return s1 == t1;
    }
};