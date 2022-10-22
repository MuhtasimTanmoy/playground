// O(n log n) running time + O(1) memory
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//     }
// };


// O(N log K) running time + O(K) memory
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;
//         for (auto num: nums)  pq.push(num);
//         while (--k) pq.pop();
//         return pq.top();
//     }
// };


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num: nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();            
    }
};