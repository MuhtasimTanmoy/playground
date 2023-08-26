class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> count;
        auto max_f = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            auto c = s[i];
            max_f = max(max_f, ++count[c]);
            if (res - max_f < k) res++;
            else count[s[i - res]]--;
        }
        return res;
    }
};