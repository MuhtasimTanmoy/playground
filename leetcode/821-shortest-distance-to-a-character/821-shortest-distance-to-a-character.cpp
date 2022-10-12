class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int sz = s.size();
        vector<int> res(sz, sz + 1);
        for (int i = 0; i < s.size(); i++) if (s[i] == c) res[i] = 0;
        
        int counter =  sz + 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) counter = 0;
            else res[i] = min(++counter, res[i]);
        }
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == c) counter = 0;
            else res[i] = min(++counter, res[i]);
        }
        
        return res;
    }
};