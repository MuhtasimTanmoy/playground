class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<long long> bag;
        long long sum = 0;
        for (int i = 0, elem = 1; i < n; i++) {
            while (bag.count(target - elem)) elem++;
            sum += elem;
            bag.insert(elem++);
        }
        return sum;
    }
};