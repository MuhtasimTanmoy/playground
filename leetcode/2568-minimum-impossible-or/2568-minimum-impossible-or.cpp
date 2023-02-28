class Solution {
public:
    // int minImpossibleOR(vector<int>& nums) {
    //     int bits = 0;
    //     for (auto num: nums) bits |= num;
    //     for (int i = 0; i < 31; i++)
    //         if ((bits & (1 << i)) == 0)
    //             return (1 << i);
    //     throw "error";
    // }
    
     int minImpossibleOR(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int a = 1;
        while (s.count(a))
            a <<= 1;
        return a;
     }
};