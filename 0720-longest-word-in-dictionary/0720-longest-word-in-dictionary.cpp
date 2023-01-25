class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> bag(words.begin(), words.end());
        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return a.size() == b.size() ? a > b : a.size() < b.size();
        });
        for (int i = words.size() - 1; i >= 0; i--) {
            string check = "";
            for (auto c: words[i]) {
                check += c;
                if (!bag.count(check)) break;
            }
            if (check.size() == words[i].size()) return check;
        }
        return "";
    }
};