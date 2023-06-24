class Solution {
public:
    // string smallestString(string s) {
    //     bool start = false;
    //     for (auto& c: s) {
    //         if (c == 'a' && start) break;
    //         if (c == 'a' && !start) continue;
    //         if (c != 'a') start = true, c--;
    //     }
    //     return s;
    // }
    
    string smallestString(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == 'a') i++;
        if (i == n && s[n - 1] == 'a') s[n - 1] = 'z';
        while (i < n && s[i] != 'a') --s[i++];
        return s;
    }
};