class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) 
            swap(s[l], s[r]);
    }
};