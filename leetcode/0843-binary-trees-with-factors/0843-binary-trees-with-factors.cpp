class Solution {
    const int MOD = 1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long res = arr.size();
        unordered_set<int> bag(arr.begin(), arr.end());
        unordered_map<int, int> counter;
        function<long long(long)> traverse = [&](long n) {
            long long calc = 0;
            if (counter.count(n)) return counter[n];
            for (auto d :bag)
                if (n > d && n % d == 0 && bag.count(n / d)) 
                    calc = calc + (traverse(d) + 1) * (traverse(n / d) + 1);
            return counter[n] = calc % MOD;
        };
        for (auto a: arr)  res = (res + traverse(a)) % 1000000007;
        return res;
    }
};