class Solution {
public:
    string modifyString(string s) {
        auto getExcept = [&](char a, char b) -> char {
            char start = 'a';
            int index = 0;
            while(index < 26) {
                if (start + index != a && start + index != b ) 
                return (char) start + index;
                index++;
            }
            return -1;
        };
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') continue;
            auto left = i ? s[i - 1]: -1;
            auto right = i < s.size() - 1 ? s[i + 1]: -1;
            s[i] = getExcept(left, right);
        }
        
        return s;
    }
};