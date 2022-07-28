class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> bag(26, 0);
        for(auto c: s) bag[c-'a']++;
        for(auto c: t) bag[c-'a']--;
        for(auto c: bag) if (c != 0) return false;
        return true;
    }
};