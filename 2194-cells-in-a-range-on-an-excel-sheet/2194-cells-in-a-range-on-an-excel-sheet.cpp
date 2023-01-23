class Solution {
public:
//     vector<string> cellsInRange(string s) {
//         char keyStart = s[0], keyEnd = s[3]; 
//         int start = s[1] - '0', end = s.back() - '0';
        
//         vector<string> res;
//         for (char c = keyStart; c <= keyEnd; c++)
//             for (int i = start; i <= end; i++) {
//                 string item = to_string(c + 'A') + to_string(i);
//                 res.push_back(item);
//             }
//         return res;
//     }
    
    vector<string> cellsInRange(string s) {
        vector<string> res;
        for (char c = s[0]; c <= s[3]; ++c)
            for (char r = s[1]; r <= s[4]; ++r)
                res.push_back({c, r});
        return res;
    }
};