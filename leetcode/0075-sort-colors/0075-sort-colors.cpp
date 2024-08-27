class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0, two = 0, zero = 0;
        for (auto num: nums) 
            if (num == 1) one++;
            else if (num == 2) two++;
            else zero++;
        for (auto &num: nums) 
            if (zero) num = 0, zero--;
            else if (one) num = 1, one--;
            else num = 2;
    }
};