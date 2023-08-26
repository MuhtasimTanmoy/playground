// class Solution {
// public:
//     int maxDistance(vector<int>& l, vector<int>& r) {
//         int res = 0, l_size =  l.size() - 1;
//         for (int i = 0; i < r.size(); i++)
//             for (int j = 0; j <= min(i, l_size); j++)
//                 if (l[j] <= r[i]) {
//                     res = max(res, i - j);
//                     break;
//                 }
//         return res;
//     }
// };

class Solution {
public:
    int maxDistance(vector<int>& l_arr, vector<int>& r_arr) {
        int res = 0, l_len = l_arr.size(), r_len = r_arr.size();
        int i = 0, j = 0;
        while (i < l_len && j < r_len) 
            if (l_arr[i] > r_arr[j]) i++;
            else res = max(res, j++ - i);
        return res;
    }
};