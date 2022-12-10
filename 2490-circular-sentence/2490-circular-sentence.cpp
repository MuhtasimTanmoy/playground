// class Solution {
// public:
//     bool isCircularSentence(string sentence) {
//         stringstream ss(sentence);
//         string now, prev = "", firstCache;
//         while (ss >> now) {
//             if (prev.size()) { if (prev.back() != now.front()) return false; }
//             else firstCache = now;
//             prev = now;
//         }
//         return firstCache.front() == now.back();
//     }
// };

class Solution {
    public:
    bool isCircularSentence(string s) {
        for (int i = 0; i < s.size(); ++i) 
            if (s[i] == ' ' && s[i - 1] != s[i + 1])
                return false;
        return s.front() == s.back();
    }
};