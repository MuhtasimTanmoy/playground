// class SparseVector {
// public:
//     vector<int> list;
//     SparseVector(vector<int> &nums) {
//         list = nums;
//     }
    
//     int dotProduct(SparseVector& vec) {
//         int res = 0;
//         for (int i = 0; i < vec.list.size(); i++) {
//             if (!list[i] || !vec.list[i]) continue;
//             res += list[i] * vec.list[i];
//         }
//         return res;
//     }    
// };

class SparseVector {
public:
    unordered_map<int, int> m;
    SparseVector(vector<int>& A) {
        for (auto i{ 0 }; i < A.size(); ++i)
            if (A[i]) m[i] = A[i];
    }
    int dotProduct(SparseVector& other) {
        auto sum{ 0 };
        for (auto [i, x]: m)
            sum += x * other.m[i];
        return sum;
    }
};