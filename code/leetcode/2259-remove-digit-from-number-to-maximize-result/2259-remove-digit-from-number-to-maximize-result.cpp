// class Solution {
// public:
//     string removeDigit(string number, char digit) {
//         function<int(string)> mystoi = [](string s) -> int {
//             int res = 0;
//             for (auto c: s) if (c != 'r') res = res * 10 + (c - '0');
//             return res;
//         };
//         int ans = 0;
//         string str = " ";
//         for (auto &c: number) {
//             if (c == digit) c = 'r';
//             else continue;
            
//             int num = mystoi(number);
            
//             if (num > ans) {
//                 ans = num;
//                 str = number;
//             }
            
//             if (c == 'r') c = digit;
//         }
//         return str;
//     }
// };

class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        string str = number;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                number.erase(number.begin() + i);
                ans=max(ans, number);
            }
            number = str;
        }
        return ans;
    }
};