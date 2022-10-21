
/*
1 -> 1, 4

- 1
    - Keep 
    - Requires extra memory O(n)

- 2
    - Memory O(k) least recently used withj cap k

- 3
    - Compute O(nk)

- 4 
    - unodered_map -> 
    
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> li;
        for (int i = 0; i < nums.size(); i++) {
            auto num = nums[i];
            if (li.count(num)) {
                auto prevIndex = li[num];
                if ((i - prevIndex) <= k) return true;
            }
            li[num] = i;
        }
        return false;
    }
};


// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         vector<pair<int,int>> indexedNums;
//         for(int i = 0; i < nums.size(); i++) indexedNums.push_back(make_pair(nums[i], i));
//         sort(indexedNums.begin(), indexedNums.end());
        
//         for(int i = 0; i < nums.size()-1; i++)
//             if (indexedNums[i].first == indexedNums[i + 1].first)
//                 if (abs(indexedNums[i].second - indexedNums[i + 1].second) <= k)
//                     return true;
//         return false;
//     }
// };