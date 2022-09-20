class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if (s.size() != goal.size()) return false;
        
        if (s == goal) {
            vector<int> mapping(26, 0);
            for (int i = 0; i < s.size(); i++)
                if (++mapping[s[i] - 'a'] > 1) return true;
            return false;
        }
        
        vector<int> diffIndex;
        for (int i = 0; i < s.size(); i++) if (s[i] != goal[i]) diffIndex.push_back(i);
        if (diffIndex.size() != 2) return false;
        auto one = diffIndex[0], two = diffIndex[1];
        return s[one] == goal[two] && s[two] == goal[one];
    }
};