class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res = 0;
        for (auto l = 0, r = 0, one = 0, zero = 0; r < s.size(); r++) {
            one += s[r] == '1',
            zero += s[r] == '0';

            while (one > k && zero > k) 
                one -= s[l] == '1',
                zero -= s[l] == '0',
                l++;
            
            res += r - l + 1;
        }
        return res;
    }
};