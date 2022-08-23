class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> mapping(26, 0);
        for (auto c: licensePlate) if (isalpha(c)) mapping[tolower(c) - 'a']++;
        string res = "";
        int sizeRes = INT_MAX;
        for (auto word: words) {
            vector<int> snapshot = mapping;
            for (auto c: word) if (snapshot[c - 'a']) snapshot[c - 'a']--;
            bool containsAll = true;
            for (auto num: snapshot) 
                if (num) {
                    containsAll = false;
                    break;
                }
            if (containsAll) if (word.size() < sizeRes) {
                sizeRes = word.size();
                res = word;
            }
        }
        return res;
    }
};