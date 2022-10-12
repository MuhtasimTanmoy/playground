class Solution {
public:
    string maximumBinaryString(string s) {
        int ones = 0, zeros = 0, n = s.length();
        for (auto& c : s) {
            if (c == '0') zeros++;
            else if (zeros == 0) ones++;
            c = '1';
        }
        if (ones < n) s[ones + zeros - 1] = '0';
        return s;
    }
};