class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto idGenerator = [](string &a) -> vector<int> {
            vector<int> res(size(a), -1);
            int id = 0;
            unordered_map<char, int> mapping;
            for (int i = 0; i < size(a); i++) {
                if (mapping.count(a[i])) res[i] = mapping[a[i]];
                else {
                    mapping[a[i]] = id++;
                    res[i] = mapping[a[i]];
                }
            }
            return res;
        };
        auto patternMapping = idGenerator(pattern);
        vector<string> res;
        for (auto word: words) {
            auto currPattern = idGenerator(word);
            int i = 0;
            for (i = 0; i < size(currPattern); i++)
                if (currPattern[i] != patternMapping[i]) break;
            if (i == size(currPattern)) res.push_back(word);
        }
        return res;
    }
};