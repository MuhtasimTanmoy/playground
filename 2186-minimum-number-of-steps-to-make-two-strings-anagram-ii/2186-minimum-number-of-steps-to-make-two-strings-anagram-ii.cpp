class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> bag(26, 0);
        for (auto c: s) bag[c - 'a']++;
        for (auto c: t) bag[c - 'a']--;
        int res = 0;
        for(auto count: bag) if (count !=  0) res += abs(count); 
        return res;
    }
};