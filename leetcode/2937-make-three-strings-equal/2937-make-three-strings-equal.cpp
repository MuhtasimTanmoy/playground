class Solution {
public:
    int findMinimumOperations(string l, string m, string r) {
        if (l.front() != m.front() || m.front() != r.front()) return -1;
        auto min_len = min({l.size(), m.size(), r.size()}),
             total_len = l.size() + m.size() + r.size();
        for (auto i = 1; i < min_len; i++) 
            if (l[i] != m[i] || r[i] != m[i]) 
                return total_len - 3 * i;
        return total_len - 3 * min_len;
    }
};