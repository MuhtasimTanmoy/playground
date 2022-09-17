class Solution {
public:
    bool isLongPressedName(string n, string t) {
        int index = 0;
        int i = 0;
        for (i = 0; i < t.size(); i++) {
            if (n[index] == t[i]) index++;
            else if (index && n[index - 1] == t[i]) {}
            else return false;
        }
        return i == t.size() && index == n.size();
    }
};