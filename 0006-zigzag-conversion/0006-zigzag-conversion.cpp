class Solution {
public:
    string convert(string s, int numRows, string res = "") {
        if (numRows == 1) return s;
        
        vector<queue<char>> vq(numRows);
        int i = 0, add = 1;
        for (auto c: s) {
            vq[i].push(c);
            i += add;
            if (!i) add = 1;
            if (i == ( numRows - 1 )) add = -1; 
        }
        for (auto q: vq)
            while (q.size()) 
                res += q.front(), q.pop();
        return res;
    }
};