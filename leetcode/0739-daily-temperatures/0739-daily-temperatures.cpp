class Solution {
public:
    vector<int> 
        dailyTemperatures(vector<int>& temperatures) {
        auto n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> w;
        for (int i = n - 1; i >= 0; i--) {
            auto now = temperatures[i];
            while (w.size() && now >= temperatures[w.top()]) w.pop();
            res[i] = w.size() ? abs(i - w.top()): 0;
            w.push(i);
        }
        return res;
    }
};