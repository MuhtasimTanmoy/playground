class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stack;
        for (auto c: s) {
            if (stack.size() && stack.back() == c) stack.pop_back();
            else stack.push_back(c);
        }
        string res = "";
        for (auto c: stack) res += c;
        return res;
    }
};