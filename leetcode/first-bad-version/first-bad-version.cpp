// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long lo = 0, hi = n;
        
        while( lo <= hi ) {
            long long mid = ( lo + hi ) >> 1;
            if (isBadVersion(mid)) 
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
        return lo;
    }
};