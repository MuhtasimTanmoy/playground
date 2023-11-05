// class Solution {
// public:
//     int minOperations(vector<int>& nums, int res = 0) {   
//         sort(nums.begin(), nums.end());
//         for (int i = 0, find = nums[0], j = nums.size(); i < j;) 
//             if (nums[i] == find) i++, find++;
//             else j--, res++;
//         return res;
//     }
// };

class Solution {
public:
    // int minOperations(vector<int>& nums, int res = 0) {  
    //     sort(nums.begin(), nums.end());
    //     int max_len = 0, n = nums.size() - 1;
    //     function<void(int, int, int)> go = [&](auto i, auto to, auto count) {
    //         if (i > n || nums[i] > to) {
    //             max_len = max(max_len, count);
    //             return;
    //         }
    //         go(i + 1, to, count + 1);
    //         go(i + 1, nums[i] + n, 1);
    //     };
    //     go(1, nums.front() + n, 1);
    //     return n + 1 - max_len;
    // }
    
    
    int minOperations(vector<int>& A) {
        int N = A.size(), ans = N, j = 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A));
        
        int M = A.size();
        for (int i = 0; i < M; ++i) {
            while (j < M && A[j] < A[i] + N) ++j; 
            ans = min(ans, N - j + i);
        }
        return ans;
    }
};


