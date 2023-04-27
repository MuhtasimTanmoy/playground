class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        for (int i = 0; i < max(w1.size(), w2.size()); i++) {
            if (i < w1.size()) res += w1[i];
            if (i < w2.size()) res += w2[i];
        }
        return res;
    }
};