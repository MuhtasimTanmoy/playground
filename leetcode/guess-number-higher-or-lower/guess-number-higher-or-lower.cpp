/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low, high;
        high = n;
        low = 1;
        
        long long mid;
        while(low <= high) {
            mid = (low+high) >> 1;
            int res = guess(mid);
            if (res == 0)
                break;
            else if (res == -1)
                high = mid-1;
            else
                low = mid+1;
        }
        return mid;
    }
};