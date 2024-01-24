class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod = 1000000007, zeros = 0, ones = 0;
        for (auto ch : binary)
            if (ch == '1')
                ones = (zeros + ones + 1) % mod;
            else
                zeros = (zeros + ones) % mod;
        return (ones + zeros + (zeros || binary[0] == '0')) % mod;
    }
};