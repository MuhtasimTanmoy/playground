// class Solution {
// public:
//     int longestValidSubstring(string word, vector<string>& forbidden) {
//         unordered_set<string> bag;
        
//         int for_len = 0;
//         for (auto token: forbidden) 
//             bag.insert(token), for_len = max(for_len, (int) token.size());
        
//         int len = word.size(), res = 0;
//         for (auto i = len - 1, right = len; i >= 0; i--) {
//             string temp = "";
//             int j = 0;
//             for (j = i; j < right && j - i <= len; j++) {
//                 temp.push_back(word[j]);
//                 if (bag.count(temp)) {
//                     right = j;
//                     break;
//                 }
//             }
//             res = max(res, j - i);
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