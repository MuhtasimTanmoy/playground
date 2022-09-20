class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int res = 0;
        unordered_map<string,int> map;
        
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        for (auto &word: words) {
            int len = 1;
            for (int i = 0; i < word.size(); ++i) {
                auto tmp = word.substr(0, i) + word.substr(i+1);
                if (map.find(tmp) != map.end()) len = max(len, map[tmp]+1);
            }
            map[word] = len;
            res = max(res, len);
        }
        return res;
    }
};