class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int res = 0;
        for (auto i = 1; i < word.size(); ) {
            auto distance = abs(word[i] - word[i-1]);
            if (distance < 2) i += 2, res++; else i++;
        }
        return res;
    }
};