class Solution {
public:
    int maxDepth(string s) {
        vector<char> stk;
        int counter = 0, res = 0;
        for (auto c: s) 
            if (c == ')') {
                counter--;
                stk.pop_back();
            } else if (c == '(') {
                stk.push_back(c);
                counter++;
                res = max(counter, res);
            }
        return res;
    }
};