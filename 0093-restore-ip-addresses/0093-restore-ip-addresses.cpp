class Solution {
public:
//     vector<string> restoreIpAddresses(string s, vector<string> res = {}) {

//         auto isValid = [&](vector<string> li, int len = 0) {
//             for (auto l: li) {
//                 len += l.size();
//                 if (l.empty() || stoi(l) > 255) return false;
//             }
//             return len == s.size();
//         };
        
//         for (auto a = 0; a < 4; a++)
//             for (auto b = 0; b < 4; b++)
//                 for (auto c = 0; c < 4; c++)
//                     for (auto d = 0; d < 4; d++) {
//                         if (a + b + c + d != s.size()) continue;
//                         auto one = s.substr(0, a),
//                              two = s.substr(a, b),
//                              three = s.substr(a + b, c),
//                              four = s.substr(a + b + c, d);
//                         if (isValid({one, two, three, four})) 
//                             res.push_back(one + "." + two + "." + three + "." + four);
//                     }
//         return res;
//     }
    
     vector<string> restoreIpAddresses(string s) {
            vector<string> ret;
            string ans;

            for (int a=1; a<=3; a++)
            for (int b=1; b<=3; b++)
            for (int c=1; c<=3; c++)
            for (int d=1; d<=3; d++)
                if (a+b+c+d == s.length()) {
                    int A = stoi(s.substr(0, a));
                    int B = stoi(s.substr(a, b));
                    int C = stoi(s.substr(a+b, c));
                    int D = stoi(s.substr(a+b+c, d));
                    if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
                        if ( (ans = to_string(A)
                              + "."
                              + to_string(B) 
                              + "." +
                              to_string(C) + 
                              "." +
                              to_string(D))
                                .length()  == s.length() + 3)
                            ret.push_back(ans);
                }

            return ret;
        }
};