class Solution {
public:
    bool isPalondrom(string& s){
        for(int i = 0; i < s.size()/2; ++i){
            if(s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int l = 0; l <= s.size(); ++l) {
                string temp = s.substr(i, l);
                for(int j = 0; j < t.size(); ++j) {
                    for(int ll = 0; j + ll <= t.size(); ++ll) {
                        string temp2 = temp + t.substr(j, ll);
                        if (temp2.size() > ans && isPalondrom(temp2)) ans = temp2.size();
                    }
                }
            }
        }
        return ans;
    }
};

