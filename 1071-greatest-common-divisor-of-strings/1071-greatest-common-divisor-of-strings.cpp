class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if (s1.size() < s2.size()) swap(s1, s2);
        for (int i = 0; i < s2.size(); i++) 
            if (s1[i] != s2[i]) return "";
        if (s1.size() == s2.size()) return s1;
        return gcdOfStrings(s1.substr(s2.size()), s2);
    }
};