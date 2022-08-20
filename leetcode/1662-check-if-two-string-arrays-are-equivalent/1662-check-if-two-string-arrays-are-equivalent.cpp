class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string string1 = accumulate(word1.begin(), word1.end(), string{});
        string string2 = accumulate(word2.begin(), word2.end(), string{});
        return string1 == string2;
    }
};