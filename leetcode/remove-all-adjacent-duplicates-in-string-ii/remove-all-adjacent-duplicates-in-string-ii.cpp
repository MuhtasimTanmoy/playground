class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char, int>> stack;
        int sameCharCount = 0;
        
        for(auto c: s) {
            if (stack.empty()) stack.push({c, 1});
            else {
                auto topElem = stack.top();
                if (topElem.first != c) stack.push( {c, 1} );
                else {
                    if (topElem.second == k - 1) stack.pop();
                    else {
                        stack.pop();
                        stack.push(
                            {topElem.first, 
                             topElem.second + 1}
                        );
                    }
                }
            }
        }
        
        string result = "";
        while (!stack.empty()) {
            while(stack.top().second--) result += stack.top().first;
            
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};