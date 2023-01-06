class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mapper;
        unordered_map<char, string> revMapper;
        stringstream ss(s); string token; int matchIndex = 0;
        
        for (string token; ss >> token; matchIndex++) {
            if (matchIndex ==  pattern.size()) return false;
            auto charToken = pattern[matchIndex];
            if (mapper.count(token) 
                || revMapper.count(charToken)) {
                if (mapper[token] != charToken || revMapper[charToken] != token) return false; 
            } else {
                mapper[token] = charToken; revMapper[charToken] = token;
            }
        }
        return matchIndex == pattern.size();
    }
};