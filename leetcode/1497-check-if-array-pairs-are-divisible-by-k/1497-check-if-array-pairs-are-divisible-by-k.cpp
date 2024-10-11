// class Solution {
// public:
//     bool canArrange(vector<int>& nums, int k) {
//         unordered_map<int, int> track;
//         for (auto &num: nums) num = (num % k + k) % k, track[num]++;
        
//         int len = nums.size();
//         for (auto num: nums) {
//             if (!track.count(num)) continue;
//             track[num]--;
            
//             auto find = (k - num);
//             cout<<"find: "<<find<<endl;
            
//             if (!track.count(find)) return false;
//             track[find]--;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        for (auto a: arr) {
            auto rem = ( a % k + k ) % k;
            counter[rem]++;
        }
        for (auto [rem, value]: counter) {
            if (!rem && (value & 1)) return false;
            if (rem && counter[rem] != counter[k-rem]) return false;
        }
        return true;
    }
};