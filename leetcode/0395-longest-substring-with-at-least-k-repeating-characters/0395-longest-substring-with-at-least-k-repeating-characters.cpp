class Solution {
public:
     int longestSubstring(string s, int k) {
        if (s.empty() || k > s.size()) return 0;
        if (!k) return s.size();
         
        vector<int> um(26, 0);
        for (auto c: s) um[c-'a']++;
        
        int idx = 0;
        while (idx < s.size() && um[s[idx] - 'a'] >= k) idx++;
        if (idx == s.size()) return s.size();
        
        int left = longestSubstring(s.substr(0 , idx) , k);
        int right = longestSubstring(s.substr(idx + 1) , k);
        
        return max(left, right);
        
    }
};