class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.length();
        vector<int> dir(len + 1, 0);
        for (auto &shift: shifts) {
            int start = shift[0], end = shift[1];
            if (shift[2] == 1) dir[start]++, dir[end+1]--;
            else dir[start]--, dir[end+1]++;
        }
        long long job = 0;
        for (int i = 0; i < len; i++) {
            job += dir[i];
            auto increaseBy = (s[i] - 'a' + job) % 26;
            s[i] = (increaseBy + 26) % 26 + 'a';
        }
        return s;
    }
};