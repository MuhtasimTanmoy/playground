class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        auto maxNum = nums[0];
        for (auto num: nums) maxNum = max(maxNum, num);
        
        auto L = maxNum ? (int)(log2(maxNum)): 0;
        auto maxXor = 0;
        
        for (auto i = L; i >= 0; --i) {
            // go to the next bit by the left shift
            maxXor <<= 1;
            // set 1 in the smallest bit
            auto currXor = maxXor | 1;
            // compute all possible prefixes 
            // of length (L - i) in binary representation
            set<int> prefixes;
            for(auto num: nums) prefixes.insert(num >> i);
            // Update maxXor, if two of these prefixes could result in currXor.
            // Check if p1^p2 == currXor, i.e. p1 == currXor^p2.
            for(auto p: prefixes) 
                if (prefixes.count(currXor^p)) {
                    maxXor = currXor;
                    break;
                }
        }
        return maxXor;
    }
};