class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res;
        res.resize(size(s));
        for(int i = 0; i < size(s); i++) res[indices[i]] = s[i];
        return res;
    }
};