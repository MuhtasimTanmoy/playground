// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         divide(0, nums.size() - 1, nums);
//         return nums;
//     }
    
//     void divide(int start, int end, vector<int> &nums) {
//         if (start >= end) continue;
//         int mid = partition(start, end, nums);
//         divide(start, mid - 1, nums);
//         divide(mid + 1, end, nums);
//     }
    
//     int partition(int start, int end, vector<int> &nums) {
//         int pivot = random() % (end - start + 1) + start, idx = start - 1;
//         swap(nums[pivot], nums[end]);
//         for (int i = start; i < end; ++i)
//             if (nums[i] < nums[end])
//                 swap(nums[++idx], nums[i]);
//         swap(nums[++idx], nums[end]);
//         return idx;
//     }
// };


class Solution {
public:
    void merge(vector<int>&A, int l, int m, int r) {
        int i = l, j = m + 1, k = 0;
        vector<int>ans(r - l + 1, 0);
        while (i <= m && j <= r) {
            if (A[i] <= A[j]) ans[k] = A[i], i++;
            else ans[k] = A[j], j++;
            k++;
        }
        while(i <= m) ans[k++] = A[i++];
        while(j <= r) ans[k++] = A[j++];
        for (int i = 0; i < r - l + 1; ++i)  A[l+i] = ans[i];
    }

    void mergeSort(int left, int right, vector<int>&vec) {
        if (right <= left) return;
        int mid = (left + right) / 2;
        mergeSort(left, mid, vec);
        mergeSort(mid+1, right, vec);
        merge(vec, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};