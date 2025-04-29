// class Solution {
// public:
//     string minWindow(string S, string T) {
//         if (S.size() < T.size()) return "";
//         vector<int> t_need(128, 0), t_has(128, 0);
//         for (auto t: T) t_need[t]++;
//         auto check = [&]() {
//             for (auto i = 0; i < t_need.size(); i++)
//                 if (t_has[i] < t_need[i]) return false;
//             return true;
//         };
//         pair<int, int> keep {0, INT_MAX};
//         for (auto i = 0, j = 0; i < S.size(); i++) {
//             t_has[S[i]]++;
//             while (check()) {
//                 auto dist_before = keep.second - keep.first;
//                 if (dist_before > (i - j)) keep = {j, i};
//                 t_has[S[j++]]--; 
//             }
//         }
//         auto [from, to] = keep;
//         if (to >= S.size()) return "";
//         return S.substr(keep.first, keep.second - keep.first + 1);
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (char c : t) {
            map[c]++;
        }

        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};