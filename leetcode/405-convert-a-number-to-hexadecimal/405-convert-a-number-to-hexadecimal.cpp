class Solution {
public:
   string toHex(int num) {
        string hex = "0123456789abcdef";
        string res = "";
        int cnt = 0;
       
        if (!num) return "0";
        while (num && ++cnt <= 8) {
            res = hex[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }
};