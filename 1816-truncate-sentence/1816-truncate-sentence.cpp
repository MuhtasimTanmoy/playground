class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') count++;
            if (count == k) s.resize(i);
        }
        return s;
    }
};