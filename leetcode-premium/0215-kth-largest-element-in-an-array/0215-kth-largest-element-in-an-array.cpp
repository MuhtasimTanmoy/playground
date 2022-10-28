// O(n log n) running time + O(1) memory
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//     }
// };


// O(N log n) running time + O(n) memory
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;
//         for (auto num: nums)  pq.push(num);
//         while (--k) pq.pop();
//         return pq.top();
//     }
// };

// O(N log K) running time + O(K) memory
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (auto num: nums) {
//             pq.push(num);
//             if (pq.size() > k) pq.pop();
//         }
//         return pq.top();            
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        auto pt = [&](int left, int right) {
            if (left == right) return left;
            int rnd = random() % (right - left) + left;
            swap(nums[rnd], nums[right]);
            int index = left;
            for (int i = left; i < right; i++)
                if (nums[i] > nums[right]) {
                    swap(nums[index], nums[i]);
                    index++;
                }
            swap(nums[index], nums[right]);
            return index;
        };
        
        auto left = 0, right = (int)nums.size() - 1;
        while (left <= right) {
            auto partitionPoint = pt(left, right);
            if (partitionPoint > k - 1) right = partitionPoint - 1;
            else if (partitionPoint < k - 1) left = partitionPoint + 1;
            else return nums[partitionPoint];
        }
        throw "INVALID Partition key";
    }
};


// class Solution {
// private:
//     int partition(vector<int>& nums, int l, int r) {
//         if (l == r) return l;
//         int idx = l, randpivot = rand() % (r - l) + l; // make the pivot random
//         swap(nums[randpivot], nums[r]);
//         for (int i = l; i < r; i++)
//             if (nums[i] > nums[r]) {
//                 swap(nums[idx], nums[i]);
//                 idx++;
//             }
//         swap(nums[idx], nums[r]);
//         return idx;
//     }
    
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int l = 0, r = nums.size() - 1;
//         while (l <= r) {
//             int pivot = partition(nums, l, r);
//             if (pivot < k - 1) l = pivot + 1;
//             else if (pivot > k - 1) r = pivot - 1;
//             else return nums[pivot];
//         }
//         return INT_MIN;
//     }
// };