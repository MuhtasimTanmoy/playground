class Solution {
public:
    string interpret(string command) {
        string res = "";
        for (int i = 0; i < command.size(); i++) {
            if (i && command[i] == ')' && command[i-1] == '(') res += 'o';
            if (command[i] == '(' || command[i] == ')') continue;
            res += command[i];
        }
        return res;
    }
};