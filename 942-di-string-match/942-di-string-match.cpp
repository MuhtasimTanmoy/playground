class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> stack, res;
        for (int i = 0; i <= s.size(); i++) {
            stack.push_back(i);
            if (i == s.length() || s[i] == 'I')
                while (!stack.empty()) {
                    res.push_back(stack.back());
                    stack.pop_back();
                }
        }
        return res;
    }
};