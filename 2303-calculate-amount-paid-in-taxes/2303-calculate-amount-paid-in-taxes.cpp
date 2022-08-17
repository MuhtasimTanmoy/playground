class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int paidSoFar = 0;
        double res = 0;
        for (auto bracket: brackets) {
            double limit = min(bracket[0], income) - paidSoFar;
            double percentage = bracket[1] / 100.0;
            res += (limit * percentage);
            paidSoFar = bracket[0];
            if (bracket[0] >= income) break;
        }
        return res;
    }
};