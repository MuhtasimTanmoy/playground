class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        
        for(auto c: s) {
            if( !stack.empty() && stack.top() == c) stack.pop();
            else stack.push(c);
        }
        
        string result = "";
        while(!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};