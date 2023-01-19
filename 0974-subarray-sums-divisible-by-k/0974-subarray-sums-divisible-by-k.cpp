class Solution {
public:
    // int subarraysDivByK(vector<int>& nums, int k) {
    //     function<int(int, int)> go = [&](auto index, auto sum) {
    //         if (index == nums.size()) return 0;
    //         auto curr = nums[index] + sum;
    //         if (!(curr % k)) cout<<curr<<endl;
    //         return !(curr % k) + go(index + 1, curr) +  go(index + 1, 0);
    //     };
    //     return go(0, 0);
    // }
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : A) {
            prefix = (prefix + a % K + K) % K;
            res += count[prefix]++;
        }
        return res;
    }
};