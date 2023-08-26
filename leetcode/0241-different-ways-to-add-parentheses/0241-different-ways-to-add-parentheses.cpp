class Solution {
    unordered_map<string, vector<int>> dp;
public:
    vector<int> diffWaysToCompute(string exp) {
        if (dp.count(exp)) return dp[exp];
        
        vector<int> res;
        unordered_set<char> ops = {'+', '-', '/', '*'};
        for (int i = 0; i < exp.size(); i++) {
            if (!ops.count(exp[i])) continue;
            
            auto l = diffWaysToCompute(exp.substr(0, i)),
                 r = diffWaysToCompute(exp.substr(i + 1));
            
            for (auto t: l)
                for (auto d: r) {
                    int calc = 0;
                    if (exp[i] == '+') calc = t + d;
                    else if (exp[i] == '-') calc = t - d;
                    else calc = t * d;
                    res.push_back(calc);
                }
        }
        if (res.empty())
            res.push_back(atoi(exp.c_str()));
        return dp[exp] = res;
    }
};