class Solution {
public:
    string smallestSubsequence(string s, string ans = "") {
        vector<int> cnt (26, 0);
        for (auto c: s) ++cnt[c - 'a'];
        vector<int> seen (26, false);
        for (auto c: s) {
            --cnt[c - 'a'];
            if (seen[c - 'a']) continue;
            
            while (ans.size() && c < ans.back() && cnt[ans.back() - 'a'] > 0) 
                seen[ans.back() - 'a'] = false, 
                ans.pop_back();
            
            ans.push_back(c);
            seen[c - 'a'] = true;
        }
        return ans;
    }
};