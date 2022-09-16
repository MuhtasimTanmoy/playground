class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i = shifts.size() - 2; i >= 0; i--) shifts[i] += (shifts[i+1] % 26);
        int index = 0;
        for (auto &c: s) {
            auto addTo = (c - 'a' + shifts[index++]) % 26;
            addTo = ( addTo + 26 ) % 26;
            c = 'a' + addTo;
        }
        return s;
    }
};