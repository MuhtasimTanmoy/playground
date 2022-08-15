class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> counter;
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        for (int i = 0; i < paragraph.size(); ++i) 
            paragraph[i] = isalpha(paragraph[i]) ? tolower(paragraph[i]) : ' ';
        
        stringstream ss(paragraph);
        string word;
        while (ss >> word) {
            if (bannedSet.count(word)) continue;
            counter[word]++;
        }
        
        int tracker = 0;
        string res = "";
        for (auto [key, val]: counter)
            if (tracker < val) {
                tracker = val;
                res = key;
            }
        return res;
    }
};