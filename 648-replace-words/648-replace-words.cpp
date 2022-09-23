class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        unordered_set<string> bag(dictionary.begin(), dictionary.end());
        string word, res;
        while (ss >> word) {
            string subStr; bool added = false;
            for (char c: word) {
                subStr += c;
                if (bag.count(subStr)) {
                    res += subStr; added = true; break;
                }
            }
            if (!added) res += word;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};