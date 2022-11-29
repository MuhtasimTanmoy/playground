// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int strCount = strs.size(), minStrSize = INT_MAX;
//         for (auto str: strs) minStrSize = min(minStrSize, (int) str.size());
//         for (int i = 1; i < strs.size(); i++) 
//             for (int j = 0; j < minStrSize; j++)
//                 if (strs[0][j] != strs[i][j]) {
//                     minStrSize = j;
//                     break;
//                 }
//         return strs[0].substr(0, minStrSize);
//     }
// };

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int left = 0;
        bool run = true;
        while (run) {
            for (int i = 0; run && i < strs.size() - 1; i++) {
                auto first = strs[i], second = strs[i+1];
                if (left >= first.size() && left >= second.size()) run = false;
                if (first[left] != second[left]) run = false;
            }
            if (left >= strs[0].size()) run = false;
            if (run) res += strs[0][left++];
        }
        return res;
    }
};
