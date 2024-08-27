class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> list(127, 0);
        for (auto c: word) list[c]++;
        int diff = abs('a' - 'A'), start = 'A', res = 0;
        for (auto i = start; i <= start + 26; i++)
            if (list[i] && list[i + diff])
                res++;
        return res;                
    }
};