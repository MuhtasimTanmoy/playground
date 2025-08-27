class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first = "ab", second = "ba";
        if (y > x) swap(first, second), swap(x, y);

        int res = 0;
        auto run = [&](string& now, int point) {
            string stk;
            for (auto c: s) 
                if (stk.size() && stk.back() == now.front() && c == now.back())
                    res += point, stk.pop_back();
                else stk.push_back(c);
            return stk;
        };
        
        s = run(first, x);
        run(second, y);
        return res;
    }
};