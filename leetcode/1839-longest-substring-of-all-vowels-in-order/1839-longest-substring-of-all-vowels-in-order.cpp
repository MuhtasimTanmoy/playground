// class Solution {
// public:
//     int longestBeautifulSubstring(string word) {
//         vector<char> list = {'a', 'e', 'i', 'o', 'u'};
//         int currIndex = 0, res = 0;
//         for (int i = 0; i < size(word); i++) {
//             if (word[i] != list[currIndex]) { continue; }
            
//             currIndex = 0;
//             int len = 0;
//             while (currIndex < size(list)) {
//             if (word[i] != list[currIndex]) break;
//                 while (word[i] == list[currIndex]) { i++; len++; }
//                 currIndex++;
//             }
            
//             if (currIndex ==  size(list)) res = max(res, len);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int left = 0, right = 0, res = 0;
        while (right < word.size()) {
            if (right) {
                auto diff = word[right] - word[right-1];
                if (diff != 0 && diff != 4 && diff != 6) 
                    left = right;
            }
            if (word[left] == 'a' && word[right] == 'u')
                res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};
