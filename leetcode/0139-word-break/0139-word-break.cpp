/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> bag(dict.begin(), dict.end());
        unordered_map<int, bool> cache;
        function<bool(int)> go = [&](auto start) {
            if (start == s.size()) return true;
            if (cache.count(start)) return cache[start];
            
            bool is_possible = false;
            string builder = "";
            for (int i = start; i < s.size(); i++) {
                builder += s[i];
                if (bag.count(builder)) is_possible |= go(i + 1);
            }
            return cache[start] = is_possible;
        };
        return go(0);
    }
};
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> bag(dict.begin(), dict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        queue<int> q; q.push(0);
        while (q.size()) {
            auto start = q.front(); q.pop();
            if (start == s.size()) continue;
            
            string builder = "";
            for (int i = start; i < s.size(); i++) {
                builder += s[i];
                if (bag.count(builder) && dp[start] && !dp[i + 1]) {
                    q.push(i + 1);
                    dp[i + 1] = true;
                }
            }
        }
        return dp[s.size()];
    }
};