class Solution {
public:
    int minOperations(vector<int>& N, int k) {
        set<int> bag(N.begin(), N.end());
        auto min_elem = *bag.begin();
        if (min_elem < k) return -1;
        else return bag.size() - (min_elem == k);
    }
};