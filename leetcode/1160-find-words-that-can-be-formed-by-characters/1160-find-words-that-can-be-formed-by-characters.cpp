class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> have(26, 0);
        for (auto c: chars) have[c - 'a']++;
        int res = 0;
        for (auto word: words) {
            vector<int> now(26, 0);
            for (auto c: word) now[c - 'a']++;
            for (auto i = 0; i <= 26; i++)
                if (i == 26) res += word.size(); else if (now[i] > have[i]) break;
        }
        return res;
    }
};