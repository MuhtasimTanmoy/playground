class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long twoNumbers = 0;
        for(int i: nums) {
            twoNumbers ^= i;
        }
        
        long long lastSetBit = twoNumbers & -twoNumbers;
        
        int first = 0;
        int second = 0;
        
        for(int i: nums) {
            if ( (long long) i & lastSetBit) {
                first^=i;
            } else {
                second^=i;
            }
        }
        
        return { first, second };
    }
};



// Set based approach

// vector<int> singleNumber(vector<int>& nums) {
        
//         vector<int> result;
//         map<int, int> occurenceCount;
        
//         for( int i = 0; i < nums.size(); i++) {
//             occurenceCount[nums[i]] += 1;
//         }
        // a
//         for( auto occurencea: occurenceCount) {
//             if (occurence.second == 1) {
//                 result.push_back(occurence.first);
//             }
//         }
        
//         return result;
//     }
