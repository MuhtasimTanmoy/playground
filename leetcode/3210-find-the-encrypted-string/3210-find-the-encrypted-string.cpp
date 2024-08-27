class Solution {
public:
    // string getEncryptedString(string s, int k) {
    //     k %= 26;
    //     for (auto &c: s) {
    //         auto idx = c - 'a', to = (idx + k) % 26;
    //         c = 'a' + to;
    //     }
    //     return s;
    // }
    
    string getEncryptedString(string s, int k) {
        string ans = ""; int n = s.size();
        for (int i = 0; i < n; i++) ans.push_back(s[(i + k) % n]);
        return ans;
    }
};