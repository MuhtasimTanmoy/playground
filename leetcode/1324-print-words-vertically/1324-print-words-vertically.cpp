class Solution {
public:
    vector<string> printVertically(string s, int width = 0, 
                                   string token = "", vector<string> li = {}) {
        stringstream ss(s);
        while (ss >> token) 
            width = max(width, (int) token.size()), li.push_back(token);
        
        vector<string> res(width, "");
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < li.size(); j++) {
                auto now = li[j];
                res[i] += i < now.size() ? (char) now[i]: ' ';
            }
            while (res[i].back() == ' ') res[i].pop_back();
        }
        return res;
    }
};