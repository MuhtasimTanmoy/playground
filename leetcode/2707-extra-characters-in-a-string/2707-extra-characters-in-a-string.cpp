class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> bag(dict.begin(), dict.end());
        unordered_map<int, int> dp;
        function<int(int)> go = [&](auto i) {
            if (i >= s.size()) return 0;
            if (dp.count(i)) return dp[i];
            
            string temp = ""; int res = s.size();
            for (int itr = i; itr < s.size(); itr++) {
                temp += s[itr];
                int cur = bag.count(temp) ? 0: temp.size(),
                    nxt = go(itr + 1);
                res = min(res, cur + nxt);
            }
            return dp[i] = res;
        };
        return go(0);
    }
};