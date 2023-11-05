// 68 / 84 test cases passed.
/*
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](const auto a, const auto b) {
            return a.size() < b.size();
        });
        
        auto is_diff_by_one = [](string& a, string& b) {
            if ((b.size() - a.size()) != 1) return false;
            int no_match_count = 0;
            for (int i = 0, j = 0; i < b.size(); i++) 
                if (b[i] != a[j]) no_match_count++; 
                else j++;
            return no_match_count == 1;
        };
        
        unordered_map<string, int> dp;
        
        function<int(int, string)> go = [&](auto i, auto prev) {
            if (i == words.size()) return 0;
            
            auto key = to_string(i) + "-" + prev;
            if (dp.count(key)) return dp[key];
            
            auto now = words[i];
            int res = 0;
            if (prev.empty()) res = 1 + go(i + 1, now);
            else if (is_diff_by_one(prev, now)) res = 1 + go(i + 1, now);
            
            res = max(go(i + 1, prev), res);
            return dp[key] = res;
        };
        return go(0, "");
    }
};
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int res = 0;
        unordered_map<string,int> map;
        
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        for (auto &word: words) {
            int len = 1;
            for (int i = 0; i < word.size(); ++i) {
                auto tmp = word.substr(0, i) + word.substr(i+1);
                if (map.find(tmp) != map.end()) len = max(len, map[tmp]+1);
            }
            map[word] = len;
            res = max(res, len);
        }
        return res;
    }
};