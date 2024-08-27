class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26, INT_MAX);
        for (auto word: words) {
            vector<int> local(26, 0);
            for (auto c: word) local[c - 'a']++;
            for (auto i = 0; i < 26; i++) count[i] = min(count[i], local[i]);
        }
        vector<string> res;
        for (auto i = 0; i < 26; i++)
            while (count[i]--)
                res.push_back(string(1, i + 'a'));
        return res;
    }
};