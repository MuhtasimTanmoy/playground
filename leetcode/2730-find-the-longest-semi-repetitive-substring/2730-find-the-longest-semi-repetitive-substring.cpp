class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        vector<int> reps{-1};
        for (int i = 1; i < s.size(); i++) 
            if (s[i] == s[i - 1])
                reps.push_back(i - 1);
        
        if (reps.size() <= 2) return s.size();
              
        reps.push_back(s.size() - 1);
        int res = 0;
        for (int i = 2; i < reps.size(); i++)
            res = max(res, reps[i] - reps[i-2]);
        return res;
    }
};