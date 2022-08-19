class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="";
        string a="";
        for (int i = 0; i < word1.size(); i++) s += word1[i];
        for (int i = 0; i < word2.size(); i++) a += word2[i];
        if (s == a) return true;
        return false;
    }
};