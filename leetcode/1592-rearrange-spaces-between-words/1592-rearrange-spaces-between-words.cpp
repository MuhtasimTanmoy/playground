class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        stringstream ss(text);
        for(string word; ss >> word; words.emplace_back(move(word)));
        
        int n = words.size();
        int need = count(text.begin(), text.end(), ' ');
        int evenSpace = n == 1 ? 0 : need / (n - 1), on_last = need % n;

        string ans;
        for(auto &word : words) ans.append(word).append(evenSpace, ' ');

        if (ans.size() < text.size()) ans.append(text.size() - ans.size(), ' ');
        else ans.resize(text.size());
        return ans;
    }
};