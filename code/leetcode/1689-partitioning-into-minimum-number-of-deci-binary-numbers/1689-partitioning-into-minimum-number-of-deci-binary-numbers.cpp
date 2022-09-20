class Solution {
public:
    int minPartitions(string n) {
        int largest = 0;
        for(auto c: n) largest = max(largest, c - '0');
        return largest;
    }
};