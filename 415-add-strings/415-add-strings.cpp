class Solution {
public:
    string addStrings(string num1, string num2) {
        int s1 = num1.size(), s2 = num2.size(), i = s1-1, j = s2-1;
        string res(max(s1, s2) + 1, '0');
        int idx = res.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += num1[i--] - '0';
            if (j >= 0) carry += num2[j--] - '0';
            res[idx--] = carry % 10 + '0';
            carry /= 10;
        }
        for (int i = 0; i < res.size(); ++i) if (res[i] != '0') return res.substr(i);
        return "0";
    }
};