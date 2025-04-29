// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& N) {
//         unordered_set<int> res;
//         for (auto i = 0; i < N.size(); i++)
//             for (auto j = i; j < N.size(); j++)
//                 for (auto k = j; k < N.size(); k++)
//                     res.insert(N[i] ^ N[j] ^ N[k]);
//         return res.size();
//     }
// };

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        int cnt = 0, temp = n;
        while (temp > 0) temp >>= 1, cnt++;        
        return pow(2, cnt);
    }
};