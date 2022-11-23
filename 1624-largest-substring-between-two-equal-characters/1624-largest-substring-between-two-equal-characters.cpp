// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         unordered_map<int, int> mp;
//         int left = 0, right = s.size() - 1;
//         while (left <= right) {
//             auto leftChar = s[left], rightChar = s[right];
            
//             int distance = -1;
//             if (mp.count(leftChar)) distance = abs(mp[leftChar] - left) - 1;
//             if (mp.count(rightChar)) distance = abs(mp[rightChar] - right) - 1;
//             if (leftChar == rightChar && left != right) distance = abs(left - right) - 1;
            
//             if (distance != -1) return distance;
//             mp[leftChar] = left;
//             mp[rightChar] = right;
            
//             left++;
//             right--;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(26, -1), end(26, -1);
        int indx = 0;
        for (auto c: s) {
            auto index = c - 'a';
            if (start[index] == -1) start[index] = indx;
            else end[index] = indx;
            indx++;
        }
        int res = -1;
        for (int i = 0; i < 26; i++) {
            auto firstIndex = start[i], endIndex = end[i];
            if (firstIndex == -1 || endIndex == -1) continue;
            res = max(res, endIndex - firstIndex - 1);
        }
        return res;
    }
};