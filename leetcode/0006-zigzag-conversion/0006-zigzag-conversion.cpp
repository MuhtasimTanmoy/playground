class Solution {
public:
    string convert(string s, int n, string res = "") {
        if (n == 1) return s;
        vector<queue<char>> vq(n);
        int i = 0, add = 1;
        for (auto c: s) {
            vq[i].push(c);
            i += add;
            add = i == n - 1 ? -1: i? add: 1;
        }
        for (auto q: vq) while (q.size()) res += q.front(), q.pop();
        return res;
    }
    
    //  here, this line,
    //  add = i == n - 1 ? -1: i? add: 1; 
    //  is shorthand for
    //  if (i == 0) add = 1;
    //  else if (i == n - 1 ) add = -1; 
};