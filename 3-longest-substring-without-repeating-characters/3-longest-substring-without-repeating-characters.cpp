// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int longest = 0;
//         unordered_set<char> bag;
//         int left = 0, right = 0;
//         while (right < s.size()) {
//             auto curr = s[right++];
//             while (bag.count(curr)) bag.erase(s[left++]);
//             bag.insert(curr);
//             longest = max(longest, right -left);
//         }
//         return longest;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mapping;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            auto curr = s[j];
            i = mapping.count(curr) ? max(mapping[curr], i): i;
            res = max(res, j - i + 1);
            mapping[curr] = j + 1;
        }
        return res;
    }
};