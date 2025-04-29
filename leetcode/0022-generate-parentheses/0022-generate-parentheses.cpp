class Solution {
    vector<string> res;
    
    void generate(int n, int remain, string s) {
        if (n == 0 && remain == 0) {
            res.push_back(s);
            return;
        }
        
        if (n) 
            s += '(',
            generate(n - 1, remain + 1, s),
            s.pop_back();
        
        if (remain) 
            s += ')',
            generate(n, remain - 1, s);
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n, 0, s);
        return res;
    }
};