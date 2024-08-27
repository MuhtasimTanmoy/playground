class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for (auto i = 0; i < s.size() && j < t.size(); i++) 
            if (s[i] == t[j]) j++;
        return t.size() - j;
    }
};