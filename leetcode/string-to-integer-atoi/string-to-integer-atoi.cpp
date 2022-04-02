class Solution {
public:
    int myAtoi(string s) {
        int num = 0, sign = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '+' || s[i] == '-') {
                sign = s[i] == '-' ? -1 : 1;
                ++i;
            }
            while (i < s.size() && isdigit(s[i])) {
                // INT_MAX = 2147483647  
                // INT_MIN = -2147483648
                if (num > INT_MAX/10 || num == INT_MAX/10 && s[i] > '7') {
                    return INT_MAX;
                }
                if (num < INT_MIN/10 || num == INT_MIN/10 && s[i] > '8') {
                    return INT_MIN;
                }
                num = num*10 + sign*(s[i++]-'0');
            }
            break;
        }
        cout<<INT_MAX<<"  "<<INT_MIN<<endl;
        return num;
    }
};


// int myAtoi(string s) {
//         stringstream ss(s);
//         long ans=0;
//         ss>>ans;
//         if(ans>INT_MAX)
//             return INT_MAX;
//         else if(ans<INT_MIN)
//             return INT_MIN;
//         return ans;
//     }