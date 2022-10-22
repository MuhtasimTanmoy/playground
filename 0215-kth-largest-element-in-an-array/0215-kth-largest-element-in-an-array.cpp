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

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         //partition rule: >=pivot   pivot   <=pivot
//         int left = 0, right = nums.size() - 1, idx = 0;
//         while(1) {
//             idx = partition(nums, left, right);
//             if(idx == k-1) break;
//             else if (idx < k-1) left = idx + 1;
//             else right= idx - 1;
//         }
//         return nums[idx];
//     }
    
//     int partition(vector<int>& nums,int left,int right) {
//         int pivot = nums[left], l = left + 1, r = right;
//         while (l <= r) {
//             if (nums[l] < pivot && nums[r] > pivot) swap(nums[l++], nums[r--]);
//             if (nums[l] >= pivot) ++l;
//             if (nums[r] <= pivot) --r;
//         }
//         swap(nums[left], nums[r]);
//         return r;
//     }
// };


class Solution {
private:
    int partition(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int idx=l;
        int randpivot=rand()%(r-l)+l; // make the pivot random
        swap(nums[randpivot],nums[r]);
        
        for (int i=l; i<r; i++) {
            if (nums[i]>nums[r]) {
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        swap(nums[idx],nums[r]);
        return idx;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,n=nums.size(),r=n-1;
        while (l<=r) {
            int pivot=partition(nums,l,r);
            if (pivot<k-1) {
                l=pivot+1;
            } else if (pivot>k-1) {
                r=pivot-1;
            } else return nums[pivot];
        }
        return INT_MIN;
    }
};