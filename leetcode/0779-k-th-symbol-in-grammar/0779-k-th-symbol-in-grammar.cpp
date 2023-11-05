class Solution {
public:
    int kthGrammar(int n, int k) {
        // string now = "0";
        // while (--n) {
        //     string temp = "";
        //     for (auto c: now) temp += c == '0' ? "01": "10";
        //     now = temp;
        // }
        // return now[k-1] - '0';
        return __builtin_popcount(k - 1) & 1;
    }
};