class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for (auto i = 2; i < num.size(); i++) 
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) 
                if (res.empty() || res.front() < num[i])
                    res = num[i];
        return res + res + res;
    }
};