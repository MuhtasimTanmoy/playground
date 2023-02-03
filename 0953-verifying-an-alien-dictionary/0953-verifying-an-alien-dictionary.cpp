class Solution {
public:
    // bool isAlienSorted(vector<string>& words, string order) {
    //     vector<int> map(27, 0);
    //     for (auto i = 0; i < order.size(); i++) map[order[i] - 'a'] = i;
    //     for (int i = 1; i < words.size(); i++) {
    //         auto first = words[i-1][0] - 'a', second = words[i][0] - 'a';
    //         if (map[first] > map[second]) return false;
    //     }
    //     return true;
    // }
    
    bool isAlienSorted(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++) mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};