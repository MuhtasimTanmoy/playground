class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if (p.size() > s.size()) return {};
        
        vector<int> tracker(26, 0);
        for (auto c: p) tracker[c - 'a']++;
        
        vector<int> calc(26, 0);
        auto isEq = [&]() {
            for (int i = 0; i < 26; i++) 
                if (tracker[i] != calc[i]) 
                    return false;
            return true;
        };
        
        vector<int> res;
        for (int i = 0, j = 0; i < s.size(); i++) {
            calc[s[i] - 'a']++;
            if ((i - j) == p.size()) calc[s[j++] - 'a']--;
            if (isEq()) res.push_back(j);
        }
        return res;
    }
};