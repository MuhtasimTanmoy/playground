class Solution {
public:
    // int getWinner(vector<int>& arr, int k) {
    //     if (arr.front() < arr[1]) swap(arr[0], arr[1]);
    //     auto most_win = 0, res = 0, winner_val = arr.front();
    //     for (auto i = 1, winner_count = 0; i < arr.size(); i++) {
    //         if (arr[i - 1] > arr[i]) swap(arr[i], arr[i - 1]), winner_count++;
    //         else winner_val = arr[i], winner_count = 1;
    //         if (winner_count > most_win)
    //             most_win = winner_count,
    //             res = winner_val;
    //         if (most_win == k) return res;
    //     }
    //     return winner_val;
    // }
    
    int getWinner(vector<int>& A, int k) {
        int cur = A[0], win = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > cur) {
                cur = A[i];
                win = 0;
            }
            if (++win == k) break;
        }
        return cur;
    }
};