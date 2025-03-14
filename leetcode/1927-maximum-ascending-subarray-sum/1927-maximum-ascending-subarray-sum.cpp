class Solution {
public:
    int maxAscendingSum(vector<int>& N) {
        int sum = N.front();
        for (auto i = 1, now = N.front(); i < N.size(); i++) {
            if (N[i] > N[i-1]) now += N[i]; else now = N[i];
            sum = max(sum, now);
        }
        return sum;
    }
};