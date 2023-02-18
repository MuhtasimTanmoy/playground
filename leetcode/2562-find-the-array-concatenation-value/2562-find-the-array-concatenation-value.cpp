class Solution {
public:
    long long findTheArrayConcVal(vector<int>& n, long long res = 0) {
        int l = 0, r = n.size() - 1;
        while (l < r) {
            auto nStr = to_string(n[l++]) + to_string(n[r--]);
            res += stoi(nStr);
        }
        if (l == r) res += n[l];
        return res;
    }
};