class Solution {
public:
    bool isDecomposable(string s) {
        s.push_back(' ');
        
        int len = 1; bool done = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i]) len++; 
            else {
                if (len == 2) if (done == false) done = true; else return false;
                else if (len == 3) {}
                else return false;
                len = 1;
            }
            if (len == 3) len = 1, i++;
        }
        return done;
    }
};