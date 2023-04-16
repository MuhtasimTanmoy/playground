class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums, int res = 0) {
        auto is_prime = [](int num) {
            if (num <= 1) return false;
            for (int i = 2; i * i <= num; i++)
                if (num % i == 0) return false;
            return true;
        };
        for (int i = 0; i < nums.size(); i++) {
            auto l = nums[i][i], r = nums[i][nums.size() - i - 1];
            if (is_prime(l) && l > res) res = l;
            if (is_prime(r) && r > res) res = r;
        }
        return res;
    }
};