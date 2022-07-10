// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int rem1 = 0, rem2 = 0;
//         for (int i = 2; i <= size(cost); i++) {
//             auto now = min(rem1 + cost[i-1], rem2 + cost[i-2]);
//             rem2 = rem1;
//             rem1 = now;
//         }
//         return rem1;
//     }
// };

// Explore all cases top down
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = size(cost);
//         function<int(int)> go = [&](int i) {
//             if (i >= n) return 0;
//             return cost[i] + min(go(i+1), go(i+2));
//         };
//         return min(go(0), go(1));
//     }
// };

// Memo
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = size(cost);
//         unordered_map<int, int> bag;
//         function<int(int)> go = [&](int i) {
//             if (i >= n) return 0;
//             if (bag.count(i)) return bag[i];
//             return bag[i] = cost[i] + min(go(i+1), go(i+2));
//         };
//         return min(go(0), go(1));
//     }
// };

// bottom up
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = size(cost);
//         vector<int> bag(n+2, 0);
//         for(int i = n - 1; i >= 0; i--) bag[i] = cost[i] + min(bag[i+1], bag[i+2]);
//         return min(bag[0], bag[1]);
//     }
// };

// Bottom up less variable
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = size(cost);
        int left = 0;
        int right = 0;
        for(int i = n - 1; i >= 0; i--) {
            auto now = cost[i] + min(left, right);
            left = right;
            right = now;
        }
        return min(left, right);
    }
};