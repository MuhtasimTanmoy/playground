class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = s.size() / 2; i >= 1; i--) 
            if (n % i == 0)
                if (s.substr(i) == s.substr(0, n - i))
                    return true;
        return false;
    }
};