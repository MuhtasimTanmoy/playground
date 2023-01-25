// Goes out of scope
class Solution {
public:
    long long smallestNumber(long long num) {
        if (num > 0) {
            auto numStr = to_string(num);
            sort(numStr.begin(), numStr.end());
            int index = 0;
            while (index < numStr.size()) {
                if (numStr[index] - '0') {
                    swap(numStr[0], numStr[index]);
                    break;
                }
                index++;
            }
            return stoll(numStr);
        } else{
            auto numStr = to_string(abs(num));
            sort(numStr.begin(), numStr.end(), greater<int>());
            return -1 * stoll(numStr);
        }
        throw "error";
    }
};