class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = ""; 
        for (auto i = 0, left = 0, one_count = 0; i < s.size(); i++) {
            one_count += s[i] == '1';
            if (one_count != k) continue;
            
            while (s[left] == '0') left++;
            auto can_be = s.substr(left, i - left + 1);
            auto is_ans = ans.empty()
                        || can_be.size() < ans.size()
                        || can_be.size() == ans.size() && can_be < ans;
            if (is_ans) ans = can_be;
            one_count -= s[left++] == '1';
        }
        return ans;
    }
};