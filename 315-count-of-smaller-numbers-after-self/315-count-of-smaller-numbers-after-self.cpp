// Segment Tree
// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int offset = 1e4;        // offset negative to non-negative
//         int size = 2 * 1e4 + 1;  // total possible values in nums, +1 for zero
//         vector<int> tree(size * 2);
//         vector<int> result;

//         for (int i = nums.size() - 1; i >= 0; i--) {
//             int smaller_count = query(0, nums[i] + offset, tree, size);
//             result.push_back(smaller_count);
//             update(nums[i] + offset, 1, tree, size);
//         }
//         reverse(result.begin(), result.end());
//         return result;
//     }

//     // implement segment tree
//     void update(int index, int value, vector<int>& tree, int size) {
//         index += size;  // shift the index to the leaf
//         // update from leaf to root
//         tree[index] += value;
//         while (index > 1) {
//             index /= 2;
//             tree[index] = tree[index * 2] + tree[index * 2 + 1];
//         }
//     }

//     int query(int left, int right, vector<int>& tree, int size) {
//         // return sum of [left, right)
//         int result = 0;
//         left += size;  // shift the index to the leaf
//         right += size;
//         while (left < right) {
//             // if left is a right node
//             // bring the value and move to parent's right node
//             if (left % 2 == 1) {
//                 result += tree[left];
//                 left++;
//             }
//             // else directly move to parent
//             left /= 2;
//             // if right is a right node
//             // bring the value of the left node and move to parent
//             if (right % 2 == 1) {
//                 right--;
//                 result += tree[right];
//             }
//             // else directly move to parent
//             right /= 2;
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 2;  // total possible values in nums plus one dummy
        vector<int> tree(size);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(nums[i] + offset, tree);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement Binary Index Tree
    void update(int index, int value, vector<int>& tree, int size) {
        index++;  // index in BIT is 1 more than the original index
        while (index < size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index, vector<int>& tree) {
        // return sum of [0, index)
        int result = 0;
        while (index >= 1) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }
};