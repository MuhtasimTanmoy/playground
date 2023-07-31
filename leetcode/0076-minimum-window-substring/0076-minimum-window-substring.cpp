class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tracker(127, 0), counter(127, 0);
        for (auto c: t) tracker[c]++;
        
        auto is_valid = [&]() {
            for (int i = 0; i < 127; i++) if (counter[i] < tracker[i])  return false;
            return true;
        };
        deque<char> res, ans;
        for (int r = 0, l = 0; r < s.size(); r++) {
            counter[s[r]]++;
            res.push_back(s[r]);
            while (is_valid() && l <= r) {
                if (res.size() < ans.size() || ans.empty()) ans = res;
                counter[s[l++]]--;
                res.pop_front();
            }
        }
        string to(ans.begin(), ans.end());
        return to; 
    }
};