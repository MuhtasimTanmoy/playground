// class Solution {
// public:
//     int reversePairs(vector<int>& N) {
//         int res = 0;
//         for (auto i = 0; i < N.size(); i++)
//             for (auto j = i + 1; j < N.size(); j++) 
//                 if (1LL * N[i] > 1LL * 2 * N[j]) res++;
//         return res;
//     }
// };
//
// class Solution {
// public:
//     int reversePairs(vector<int>& N) {
//     }
// };

// class Node {
// public:
//     Node *left, *right;
//     int val;
//     int count_ge;

//     Node(int val) {
//         this->val = val;
//         this->count_ge = 1;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// Node* insert(Node* head, int val) {
//     if (head == NULL) return new Node(val);
//     else if (val == head->val) head->count_ge++;
//     else if (val < head->val) head->left = insert(head->left, val);
//     else
//         head->count_ge++,
//         head->right = insert(head->right, val);
//     return head;
// }

// int search(Node* head, long long target) {
//     if (head == NULL) return 0;
//     else if (target == head->val) return head->count_ge;
//     else if (target < head->val) return head->count_ge + search(head->left, target);
//     else return search(head->right, target);
// }

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         Node* head = NULL;
//         int n = nums.size(), count = 0;
//         for (int i = 0; i < n; i++) 
//             count += search(head, nums[i] * 2LL + 1),
//             head = insert(head, nums[i]);
//         return count;
//     }
// };


// class Fenwick {
//     vector<int> bits;
//     public:
//     FenWickTree(int n): bits(n + 1, 0) {}

//     void insert(int index, int diff) {
//         while (index < bits.size())
//             bits[index] += diff,
//             index += index & -index;
//     }

//     int get(int index) {
//         int res = 0;
//         while (index > 0)
//             res += bits[index],
//             index -= index & -index;
//     }
// }

void update(vector<int>& BIT, int index, int val) {
    while (index > 0) 
        BIT[index] += val,
        index -= index & (-index);
}

int query(vector<int>& BIT, int index) {
    int sum = 0;
    while (index < BIT.size())
        sum += BIT[index],
        index += index & (-index);
    return sum;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> sc(nums);
        sort(sc.begin(), sc.end());
        vector<int> BITS(n + 1, 0);

        int count = 0;
        for (int i = 0; i < n; i++) {
            auto idx = lower_bound(sc.begin(), sc.end(), 2LL * nums[i] + 1) - sc.begin() + 1;
            count += query(BITS, idx);

            auto u = lower_bound(sc.begin(), sc.end(), nums[i]) - sc.begin() + 1;
            update(BITS, u, 1);
        }
        return count;
    }
};