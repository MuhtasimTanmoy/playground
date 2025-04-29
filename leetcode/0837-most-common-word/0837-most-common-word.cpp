class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> counter;
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        for (int i = 0; i < paragraph.size(); ++i) 
            paragraph[i] = isalpha(paragraph[i]) ? tolower(paragraph[i]) : ' ';
        stringstream ss(paragraph);
        int tracker = 0;
        string word, res;
        while (ss >> word) {
            if (bannedSet.count(word)) continue;
            if ( ++counter[word] > tracker ) 
                tracker = counter[word],
                res = word;
        }
        return res;
    }
};