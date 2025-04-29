// k bags
// weights[i] is the weight of the ith marble

// Divide the marbles into the k bags according to the following rules:

// No bag is empty
// i - j all marbles in same bag
// Cost of the bag is weights[i] + weights[j]

class Solution {
public:
    long long putMarbles(vector<int>& W, int k) {
        for (auto i = 0; i < W.size() - 1; i++) W[i] += W[i + 1];
        W.pop_back();
        sort(W.begin(), W.end());
        long long res = 0, len = W.size() - 1;
        for (int i = 0; i < k - 1; i++) res += W[len - i] - W[i];
        return res;
    }
};