class Solution {
public:
    string addBinary(string a, string b) {
        if (size(b) > size(a)) swap(a, b);
        int rem = 0;
        for(int i = size(a) - 1, j = size(b) - 1; i >= 0; i--, j--) {
            auto addition = (a[i] - '0') +  (j < 0 ? 0 : (b[j] - '0')) + rem;
            rem = addition >= 2 ? 1 : 0;
            addition = (addition == 1 || addition == 3) ? 1: 0;
            a[i] = '0' + addition;
        }
        if (rem) a = '1' + a;
        return a;
    }
};