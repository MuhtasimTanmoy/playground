class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        auto kstr = to_string(k);
        reverse(kstr.begin(), kstr.end());
        
        int arrIdx = 0, carry = 0, kIdx = 0;
        while (arrIdx < num.size() || kIdx < kstr.size()) {
            auto val = ( arrIdx < num.size() ? num[arrIdx]: 0 )
                       + ( kIdx < kstr.size() ? kstr[kIdx++] - '0': 0 )
                       + carry;
            if (val > 9) val %= 10, carry = 1; else carry = 0;
            if (arrIdx < num.size()) num[arrIdx] = val;
            else num.push_back(val);
            arrIdx++;
        }
        
        if (carry) num.push_back(carry);
        reverse(num.begin(), num.end());
        return num;
    }
};