class Solution {
public:
    string interpret(string command) {
        string res = "";
        for (int i = 0; i < command.size(); i++) {
            auto curr = command[i];
            if (i && curr == ')' && command[i-1] == '(') res += 'o';
            if (curr == '(' || curr == ')') continue;
            res += curr;
        }
        return res;
    }
};