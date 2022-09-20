class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> bag(26, 0);
        for (auto c: s) bag[c-'a']++;
        string res = "";
        for (auto c: order) 
            while (bag[c-'a']--) res += c;
        for (auto c: s) if (bag[c-'a'] > 0) res += c;
        return res;
    }
};