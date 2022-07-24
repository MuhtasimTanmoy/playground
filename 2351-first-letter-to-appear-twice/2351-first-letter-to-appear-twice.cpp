class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> bag(127, false);
        for(auto c: s) {
            if (bag[c]) return c;
            bag[c] = true;
        }
        return s[0];
    }
};