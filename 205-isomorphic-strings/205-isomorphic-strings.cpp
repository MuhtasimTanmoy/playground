class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> fw(128, -1), bw(128, -1);
        for (int i = 0; i < s.size(); ++i)
            if (fw[s[i]] == -1) {
                fw[s[i]] = t[i];
                if (bw[t[i]] != -1) return false;
                else bw[t[i]] = s[i];
            } else if (fw[s[i]] != t[i]) return false;
        return true;
    }
};