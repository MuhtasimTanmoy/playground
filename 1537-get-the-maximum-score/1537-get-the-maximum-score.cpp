// class Solution {
// public:
//     int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
//         function<int(int, int)> go = [&](int nums1Index, int nums2Index) {
            
//             if (nums1Index >= nums1.size()) return 0;
//             if (nums2Index >= nums2.size()) return 0;
            
//             auto num1 = nums1[nums1Index];
//             auto num2 = nums2[nums2Index];
            
//             auto oneWay = num1 + go(nums1Index + 1, nums2Index);
//             auto twoWay = num2 + go(nums1Index, nums2Index + 1);
//             auto res = max(oneWay, twoWay);
            
//             if (num1 == num2) {
//                 auto oneWayAlter = num1 + go(nums1Index, nums2Index + 1);
//                 res = max(oneWayAlter, res);
//                 auto twoWayAlter = num2 + go(nums1Index + 1, nums2Index);
//                 res = max(twoWayAlter, res);
//             }
            
            
// //             auto it2 = lower_bound(nums2.begin(), nums2.end(), num1);
// //             if (it2 != nums2.end()) {
// //                 auto moveToTwo = num1 + go(INT_MAX, it2 - nums2.begin() + 1);
// //                 res = max(moveToTwo, res);
// //             }
            
// //             auto it1 = lower_bound(nums1.begin(), nums1.end(), num2);
// //             if (it1 != nums1.end()) {
// //                 auto moveToOne = num2 + go(it1 - nums1.begin() + 1, INT_MAX);
// //                 res = max(moveToOne, res);
// //             }
            
//             return res;
//         };
        
//         return go(0, 0);
//     }
// };


class Solution {
public:
    #define ll long long 
    int MOD = 1e9 + 7 ;
    int maxSum(vector<int>& A, vector<int>& B) {
        
        int a = 0 , b = 0 ;
        ll maxSum = 0 , sumA = 0 , sumB = 0 ;
        
        while(a < A.size() and b < B.size()){
            if(A[a] < B[b]) sumA += A[a++] ;
            else if(B[b] < A[a]) sumB += B[b++] ;
            else maxSum += max(sumA,sumB) + A[a] , sumA = sumB = 0, ++a,++b ;
        }
        
        while(a < A.size()) sumA += A[a++] ;
        while(b < B.size()) sumB += B[b++] ;
        
        maxSum += max(sumA,sumB) ;
        return maxSum % MOD ;
    }
};