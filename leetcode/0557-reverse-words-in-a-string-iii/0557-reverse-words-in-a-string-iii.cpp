class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string res = "", token;
        while (ss >> token) 
            reverse(token.begin(), token.end()),
            res += token,
            res += " ";
        res.pop_back();
        return res;
    }
};