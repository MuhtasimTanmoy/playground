// TLE
/*
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int index = -1;
        for (auto n: nums) {
            index++;
            int cnt = numsDivide.size();
            for (auto d: numsDivide) if (d % n == 0) cnt--;
            if (!cnt) return index;
        }
        return -1;
    }
};
*/

class Solution {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
public:
    int minOperations(vector<int>& nums, vector<int>& numsd) {
        int target = numsd[0];
        for (int a: numsd)
            target = gcd(target, a);
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) 
            if (target % nums[i] == 0) 
                return i;
        return -1;
    }
};