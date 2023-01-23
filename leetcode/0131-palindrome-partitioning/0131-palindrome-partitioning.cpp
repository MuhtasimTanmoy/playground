class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; vector<string> par;
        auto isPalindrome = [&s](int l, int r) {
            while (l < r) if (s[l++] != s[r--]) return false;
            return true;
        };
        function<void(int)> part = [&](auto start) {
            if (start == s.size()) res.push_back(par);
            else 
                for (auto i = start; i < s.size(); i++) 
                    if (isPalindrome(start, i)) {
                        par.push_back(s.substr(start, i - start + 1));
                        part(i + 1);
                        par.pop_back();
                    }
        };
        part(0);
        return res;
    }
};