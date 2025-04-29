class Solution {
public:
    long long maximumTripletValue(vector<int>& N) {
        vector<int> left_largest;
        int largest = 0;
        for (auto c: N)
            largest = max(c, largest),
            left_largest.push_back(largest);

        long long res = 0, max_so_far = 0;
        for (int i = 1; i < N.size() - 1; i++) {
            auto l = left_largest[i-1];
            max_so_far = max(max_so_far, 1LL * ( l - N[i] ));           
            res = max(res, max_so_far * N[i + 1]);
        }
        return res;
    }
};