// class Solution {
// public:
//     int longestValidSubstring(string word, vector<string>& bans) {
//         auto is_in = [&](string& s) {
//             for (auto ban: bans) if (s.find(ban) != string::npos) return true;
//             return false;
//         };
//         int res = 0, len = word.size();
//         for (int i = 0; i < len; i++) {
//             string temp = word.substr(i, len - i);
//             auto sub_len = len - i;
//             while (sub_len--) {
//                 if (!is_in(temp)) {
//                     res = max(res, (int) temp.size());
//                     break;
//                 }
//                 temp.pop_back();
//             }
//         }
//         return res;      
//     }
// };

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& bans) {
        unordered_set<string> ban_set(bans.begin(), bans.end());
        int n = word.size() - 1, right = n, res = 0;
        for (int i = n; i >= 0; i--) {
            string temp = "";
            for (int l = i; l < min(i + 10, right + 1); l++) {
                temp += word[l];
                if (ban_set.count(temp)) {
                    right = l - 1;
                    break;
                }
            }
            res = max(res, right - i + 1);
        }
        return res;
    }
};