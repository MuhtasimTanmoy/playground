class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        function<int(string)> toInt = [](string s) -> int {
            int res = 0;
            for(auto c: s) {
                if (c == '-') continue;
                res = res * 10; res += (c - '0'); 
            }
            return s[0] == '-' ? -res: res;
        };
        
        stack<long long> args;
        unordered_set<char> operations = {'+', '-', '*', '/'};
        for(auto token: tokens) {
            if (token.size() == 1 && operations.count(token[0])) {
                auto secondArg = args.top(); args.pop();
                auto firstArg = args.top(); args.pop();
                long long res = 0;
                switch (token[0]) {
                    case '+':
                        res = firstArg + secondArg;
                        break;
                    case '-':
                        res = firstArg - secondArg;
                        break;
                    case '*':
                        res = firstArg * secondArg;
                        break;
                    case '/':
                        res = firstArg / secondArg;
                }
                args.push(res);
            } else args.push(toInt(token));
        }
        
        return args.top();
    }
};