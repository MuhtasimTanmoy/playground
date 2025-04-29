class Solution {
public:
    int subsetXORSum(vector<int>& N) {
        function<int(int, int)> go = [&](auto i, auto curr) {
            if (i == N.size()) return curr;
            int without = go(i + 1, curr),
                with =  go(i + 1,  N[i] ^ curr);
            return with + without;
        };
        return go(0, 0);
    }
};