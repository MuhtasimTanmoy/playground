class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        s.push_back(' ');
        for (int l = 0, r = 0; r < s.size(); r++) 
            if (s[r] == ' ')
                reverse(s.begin() + l, s.begin() + r), l = r + 1;
        s.pop_back();
    }
};