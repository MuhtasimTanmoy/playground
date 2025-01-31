class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (auto &word: words) 
            res += word.substr(0, pref.size()) == pref;
        return res;
    }
};