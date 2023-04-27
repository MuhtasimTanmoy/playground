/*

class Solution {
    void shift_left(string& t) {
        for (int i = 0; i < t.size(); i++) 
            if (t[i] == 'L') {
                auto itr = i;
                while (itr && t[itr - 1] == '_') 
                    swap(t[itr], t[itr - 1]),
                    itr--;
            }
    }
    
    void shift_right(string& t) {
        for (int i = t.size() - 1; i >= 0; i--) 
            if (t[i] == 'R') {
                auto itr = i + 1;
                while (itr < t.size() && t[itr] == '_') 
                    swap(t[itr], t[itr - 1]),
                    itr++;
            }
    }
public:
    bool canChange(string s, string t) {
        shift_left(t);
        shift_right(t);
        
        shift_left(s);
        shift_right(s);
        
        return s == t;
    }
};

*/

class Solution {
public:
    bool canChange(string s, string t) {
        int i = 0, j = 0, n = s.size();
        for (; i < n || j < n; ++i, ++j) {
            while (i < n && s[i] == '_') ++i;
            while (j < n && t[j] == '_') ++j;
            if (i == n || j == n 
                || s[i] != t[j] 
                || (s[i] == 'L' && i < j) 
                || (s[i] == 'R' && i > j))
                break;
        }
        return i == n && j == n;
    }
};