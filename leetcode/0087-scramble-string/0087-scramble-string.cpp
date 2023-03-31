class Solution {
    unordered_map<string,bool> ump;
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        
        string key = s1 + " "+ s2;
        if (ump.count(key)) return ump[key];
            
        int len = s1.length();
        int count[26] = {0};
        for (int i = 0; i < len; i++) 
            count[s1[i]-'a']++,
            count[s2[i]-'a']--;
        
        for(auto c: count) if (c) return false;
        
        bool flag = false;
        for (int i = 1; i <= len-1; i++) {
            if (isScramble(s1.substr(0,i), 
                           s2.substr(0,i)) 
               && isScramble(s1.substr(i), 
                             s2.substr(i))) {
                flag |= true;
                break;
            }
            
            if (isScramble(s1.substr(0,i), 
                           s2.substr(len-i)) 
                && isScramble(s1.substr(i), 
                              s2.substr(0,len-i))) {
                flag |= true;
                break;
            }
        }
        ump[key] = flag;
        return flag;
    }
};