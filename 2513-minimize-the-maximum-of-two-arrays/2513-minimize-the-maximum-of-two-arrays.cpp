class Solution {
public:
    // int minimizeSet(int divisor1, int divisor2, 
    //                 int uniqueCnt1, int uniqueCnt2, int start = 0) {
    //     while (uniqueCnt1 || uniqueCnt2) {
    //         if (uniqueCnt1 <= uniqueCnt2) 
    //             swap(uniqueCnt1, uniqueCnt2), swap(divisor1, divisor2);
    //         start++;
    //         if (start % divisor1) uniqueCnt1--;
    //         else if (uniqueCnt2) 
    //             if (start % divisor2) uniqueCnt2--;
    //     }
    //     return start;
    // }
    
    int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        long long ans = INT_MAX;
        long long low = 1, high = INT_MAX;
        auto common = lcm((long long) d1, d2);
        
        while (low <= high) {
            auto mid = ( low + high ) / 2;
            auto c1 = mid - mid / d1;
            auto c2 = mid - mid / d2;
            auto temp = mid - mid / common;
            
            if (c1 >= cnt1 and c2 >= cnt2 and temp >= cnt1 + cnt2) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};