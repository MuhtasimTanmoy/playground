class Solution {
public:
    int maxDepth(string s) {
        int counter = 0, res = 0;
        for (auto c: s) 
            if (c == ')') counter--;
            else if (c == '(')
                res = max(++counter, res);
        return res;
    }
};