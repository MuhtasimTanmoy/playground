class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> bag(26, 0), targetBag(26, 0);
        for (auto c: s) bag[c-'a']++;
        for (auto c: target) targetBag[c-'a']++;
        int res = 0;
        while(1) {
            for(int i = 0; i < 26; i++) {
                bag[i] -= targetBag[i];
                if (bag[i] < 0) return res;
            }
            res++;
        }
        return res;
    }
};