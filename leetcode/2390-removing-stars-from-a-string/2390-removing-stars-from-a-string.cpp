class Solution {
public:
    string removeStars(string s) {
        int l = 1;
        for (int r = 1; r < s.size(); r++) 
            if (s[r] != '*')
                s[l++] = s[r];
            else l--;
        s.resize(l);
        return s;
    }
};