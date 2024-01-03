class Solution {
public:
    string largestPalindromic(string nums) {
        vector<int> li(10, 0);
        for (auto num: nums) li[num - '0']++;
        string res = "", back = "";
        int one = -1;
        for (int i = 9; i >= 0; i--) {
            if (i == 0 && res.empty()) break;
            while (li[i] > 1) 
                res += '0' + i, 
                back += '0' + i, 
                li[i] -= 2;
            if (li[i] == 1) if (one < i) one = i;
        }
        reverse(back.begin(), back.end());
        if (one != -1) res += '0' + one;
        res += back;
        return res.empty() ? "0": res;
    }
};