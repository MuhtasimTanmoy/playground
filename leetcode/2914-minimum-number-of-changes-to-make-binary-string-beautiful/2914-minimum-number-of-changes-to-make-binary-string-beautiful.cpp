class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        for (int i = 1; i < s.size(); i += 2) 
            if (s[i] != s[i-1]) res++;
        return res;
    }
};