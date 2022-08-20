class Solution {
    bool followsCriteria(const string& word) {
        unordered_set<char> punctuations = {'!','.',','};
        bool has_hyphen = false;
        for (int i = 0; i < word.size(); i++)
            if (isdigit(word[i])) return false;
            else if (word[i] == '-') {
                if (i == 0 or i == word.size() - 1)  return false;
                else if (!isalpha(word[i-1]) or !isalpha(word[i+1]))
                    return false;
                else
                    if (!has_hyphen) has_hyphen = true;
                    else return false;
            } else if (punctuations.find(word[i]) != punctuations.end())
                if (i != word.size() -1) return false;        
        return true;
    }
public:
    int countValidWords(string sentence) {
        stringstream sso(sentence);
        string word;
        int count = 0;
        while (sso >> word)
            if (followsCriteria(word))
                count++;            
        return count;
    }
};