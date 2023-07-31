class Solution {
public:
    bool buddyStrings(string s, string g) {
        if (s.size() != g.size()) return false;
        if (s == g && s.size() > 1)
            return s.size() != set<char>(s.begin(), s.end()).size();
        
        vector<int> d;
        for (int i = 0; i < s.size(); i++) 
            if (s[i] != g[i])
                d.push_back(i);
        
        if (d.size() != 2) return false;
        return s[d.back()] == g[d[0]] && s[d[0]] == g[d.back()];
    }
};