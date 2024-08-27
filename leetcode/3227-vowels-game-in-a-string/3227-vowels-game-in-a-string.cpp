class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> bag = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        for (auto c: s) if (bag.count(c)) return true;
        return false;
    }
};