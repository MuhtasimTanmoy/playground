class Solution {
public:
    char findKthBit(int n, int k) {
        string builder = "0";
        auto reverseInverse = [](string& s) {
            string res = "";
            for (auto c: s) res += c == '0' ? '1': '0';
            reverse(res.begin(), res.end());
            return res;
        };
        while (--n) 
            builder = builder + "1" + reverseInverse(builder);
        return builder[k - 1];
    }
};