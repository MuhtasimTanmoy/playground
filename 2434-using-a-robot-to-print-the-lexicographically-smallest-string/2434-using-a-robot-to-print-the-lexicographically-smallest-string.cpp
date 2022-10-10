// class Solution {
// public:
//     string robotWithString(string s) {
//         string res = "";
//         string t = "";
//         t += s[0];
        
//         for (int i = 1; i < s.size(); i++) {
//             auto c = s[i];
//             if (t.size() && t.back() >= c) t += c;
//             else {
//                 if (!t.size()) continue;
//                 reverse(t.begin(), t.end());
//                 res += t;
//                 t = c;
//             }
//         }
        
//         if (t.size()) {
//             reverse(t.begin(), t.end());
//             res += t;
//         }
//         return res;
//     }
// };
// not working for "badd"

class Solution {
public:
    char low(vector<int> & freq) {
        for(int i = 0; i < 26; i++) if ( freq[i] != 0 ) return 'a' + i;
        return 'a';   
    }
    
    string robotWithString(string s) {
        stack<char> t;
        string ans = "";  
        vector<int> freq(26, 0);
        for (char c: s) freq[c - 'a']++;
        for (char c: s) {
            t.push(c);
            freq[c - 'a']--; 
            while (t.size() > 0 && t.top() <= low(freq)) {
                char x = t.top(); 
                ans += x;
                t.pop();  
            }
        }
        
        while (t.size()) {
             ans += t.top();
             t.pop();   
        }
        return ans;
    }
};