class Solution {
public:
    static string to_binary(int x) {
        int bit = 31 - __builtin_clz(x);
        string ans = "1";
        for (int i = bit - 1; i >= 0; i--) ans += (x & (1<<i)) ? '1' : '0';
        return ans;
    }
    
    static string convertDateToBinary(string& date) {
        stringstream ss(date);
        int yy, mm, dd; char c;
        ss>>yy>>c>>mm>>c>>dd;
        return to_binary(yy) + "-" + to_binary(mm) + "-" + to_binary(dd);
    }
};