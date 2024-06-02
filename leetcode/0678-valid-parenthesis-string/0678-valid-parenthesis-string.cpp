class Solution {
public:
    bool checkValidString(string s) {
        int c_min = 0, c_max = 0;
        for (auto c: s) {
            if (c == '(') c_max++, c_min++;
            else if (c == ')')  c_max--, c_min--;
            else c_max++, c_min--;
            
            if (c_max < 0) return false;
            c_min = max(c_min, 0);
        }
        return c_min == 0;
    }
};