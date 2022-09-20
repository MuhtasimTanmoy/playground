class Solution {
public:
    int secondHighest(string s) {
        int largest = -1, secondLargest = -1;
        for (auto c: s) {
            if ( c < '0' || c > '9') continue;
            int digit = c - '0';
            if (digit > largest) {
                secondLargest = largest;
                largest = digit;
            } else if (digit > secondLargest && digit != largest) secondLargest = digit;
        }
        return secondLargest;
    }
};