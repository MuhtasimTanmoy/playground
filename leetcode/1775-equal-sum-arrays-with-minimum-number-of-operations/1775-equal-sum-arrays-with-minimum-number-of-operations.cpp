class Solution {
public:
//     int minOperations(vector<int>& nums1, vector<int>& nums2, int res = 0) {
//          if (nums2.size() * 6 < nums1.size() 
//              || nums1.size() * 6 < nums2.size())
//             return -1;
        
//         auto sum1 = accumulate(nums1.begin(), nums1.end(), 0), 
//              sum2 = accumulate(nums2.begin(), nums2.end(), 0);
//         if (sum1 < sum2) swap(nums1, nums2);
//         auto diff = abs(sum1 - sum2);
        
//         sort(nums1.begin(), nums1.end(), greater<int>());
//         sort(nums2.begin(), nums2.end());
        
//         vector<int> diffLocals;
//         for (auto i = 0; i < nums1.size() && i < nums2.size(); i++) {
//             auto localDiff = abs(nums1[i] - nums2[i]);
//             diffLocals.push_back(localDiff);
//         }
//         sort(diffLocals.begin(), diffLocals.end(), greater<int>());
//         for (auto c: diffLocals) {
//             diff -= c; res++;
//             if (diff <= 0) break;
//         }
//         return diff <= 0 ? res: -1;
//     }
    
    int minOperations(vector<int>& n1, vector<int>& n2) {
        if (6 * min(n1.size(), n2.size()) <  max(n1.size(), n2.size()) ) return -1;
        
        int sum1 = accumulate(begin(n1), end(n1), 0), sum2 = accumulate(begin(n2), end(n2), 0);
        if (sum1 > sum2) swap(n1, n2);
        
        priority_queue <int, vector<int>, greater<int>> q1(begin(n1), end(n1));
        priority_queue<int> q2(begin(n2), end(n2));
        
        int cnt = 0, diff = abs(sum1 - sum2);
        while (diff > 0 && q1.size() && q2.size()) {
            ++cnt;
            auto greaterToLess = q2.top() - 1, lessToGreater = 6 - q1.top();
            if (greaterToLess > lessToGreater) diff -= greaterToLess, q2.pop();
            else diff -= lessToGreater, q1.pop();
        }
        while (diff > 0 && q1.size()) diff -= 6 - q1.top(), q1.pop(), cnt++;
        while (diff > 0 && q2.size()) diff -= q2.top() - 1, q2.pop(), cnt++;
        return diff > 0 ? -1: cnt;
    }
};