class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> bag {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        vector<char> vowels;
        for (auto c: s) if (bag.count(c)) vowels.push_back(c);
        sort(vowels.begin(), vowels.end());
        
        int i = 0;
        for (auto &c: s) if (bag.count(c)) c = vowels[i++];
        return s;
    }
};