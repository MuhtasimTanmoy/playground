class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int left = 0, 
            right = skill.size() - 1, 
            balance = 0;
        long product = 0;
        while (left < right) {
            auto leftVal = skill[left++], rightVal = skill[right--];
            product += leftVal * rightVal;
            auto sum = leftVal + rightVal;
            if (balance) if (balance != sum) return -1;
            balance = sum;
        }
        return product;
    }
};