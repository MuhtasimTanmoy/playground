class Solution {
public:
    string toLowerCase(string s) {
        for (auto &c: s) c = tolower(c);
        return s;
    }
};