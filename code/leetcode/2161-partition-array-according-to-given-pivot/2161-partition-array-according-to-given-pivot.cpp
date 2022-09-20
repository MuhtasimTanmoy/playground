class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        int sameCount = 0;
        for(auto num: nums) {
            if (num > pivot) right.push_back(num);
            else if (num < pivot) left.push_back(num);
            else sameCount++;
        }
        while(sameCount--) left.push_back(pivot);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};