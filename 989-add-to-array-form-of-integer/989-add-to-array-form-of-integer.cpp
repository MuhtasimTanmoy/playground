class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        while(k) {
            auto rem = k % 10;
            k /= 10;
            res.push_back(rem);
        }
        reverse(res.begin(), res.end());
        if (size(num) < size(res)) swap(num, res);
        int rem = 0;
        for(int i = size(num) - 1, j = size(res) - 1; i >= 0; i--, j--) {
            num[i] += (j >= 0 ? res[j] : 0) + rem;
            rem = (num[i] > 9) ? 1: 0;
            num[i] %= 10;
        }
        if (rem) num.insert(num.begin(), 1);
        return num;
    }
};