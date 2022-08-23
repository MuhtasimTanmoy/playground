// class Solution {
// public:
//     int numOfPairs(vector<string>& nums, string target) {
//         int count = 0;
//         auto targetHash = hash<string>{}(target);
//         for (int i = 0; i < nums.size() ; i++) 
//             for (int j = 0; j < nums.size(); j++) {
//                 if (i == j) continue;
//                 if (nums[i].size() + nums[j].size() != target.size()) continue;
//                 auto concat = nums[i] + nums[j];
//                 auto hashConcat = hash<string>{}(concat);
//                 if (hashConcat == targetHash) count++;
//             }
//         return count;
//     }
// };


class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) m[nums[i]]++;
        int count = 0, l = target.length();
        for (int i = 0; i < l; i++) {
            string s=target.substr(0, i + 1);
            string t=target.substr(i + 1, l - i - 1);
            if (m.count(s) && m.count(t))
                count += m[s] * ( m[t] - (s == t ? 1: 0));
        }
        return count;
    }
};