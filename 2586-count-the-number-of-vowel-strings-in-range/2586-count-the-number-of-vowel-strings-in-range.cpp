class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right, int res = 0) {
        unordered_set<char> bag {'a', 'e', 'i', 'o', 'u'};
        for (int i = left; i <= right; i++) {
            auto word = words[i];
            if (bag.count(word[0]) && bag.count(word.back())) res++;
        }
        return res;
    }
};