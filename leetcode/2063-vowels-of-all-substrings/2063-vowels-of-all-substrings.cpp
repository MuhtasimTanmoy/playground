class Solution {
public:
    long long countVowels(string word) {
        unordered_set<char> bag {'a', 'e', 'i', 'o', 'u'};
        long long n = word.size(), res = 0;
        for (int i = 0; i < n; i++)
            res += bag.count(word[i]) * (i + 1) * (n - i);
        return res;
    }
};