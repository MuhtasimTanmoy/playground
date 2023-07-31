class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words, int res = 0) {
        unordered_set<string> bag(words.begin(), words.end());
        for (auto word: words) {
            auto rev_word = word;
            reverse(rev_word.begin(), rev_word.end());
            if (rev_word == word) continue;
            if (bag.count(rev_word))
                bag.erase(word),
                bag.erase(rev_word),
                res++;
        }
        return res;
    }
};