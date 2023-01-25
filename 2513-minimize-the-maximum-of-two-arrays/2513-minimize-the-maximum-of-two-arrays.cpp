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
        auto common = (long long) d1 * d2 / __gcd(d1,d2); // lcm((long long) d1, d2);
        
        while (low <= high) {
            auto mid = ( low + high ) / 2;
            auto notDivisibleByd1 = mid - mid / d1;
            auto notDivisibleByd2 = mid - mid / d2;
            auto notDivisibleByBoth = mid - mid / common;
            
            if (notDivisibleByd1 >= cnt1 
                and notDivisibleByd2 >= cnt2 
                and notDivisibleByBoth >= cnt1 + cnt2) 
                    ans = mid, high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};