class Solution {
public:
    string reversePrefix(string w, char ch) {
        int l = 0, r = 0;
        for (int i = 0; i < w.size(); i++) 
            if (w[i] == ch) {
                r = i;
                break;
            }
        while (l < r) swap(w[l++], w[r--]);
        return w;
    }
};