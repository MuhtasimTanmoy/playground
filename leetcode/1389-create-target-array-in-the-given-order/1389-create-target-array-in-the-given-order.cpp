class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        list<int> l;
        for(int i = 0; i < nums.size(); i++) {
            auto pos = index[i], val = nums[i];
            if (index[i] >= l.size()) l.push_back(val);
            else {
                auto start = l.begin();
                while (pos--) start++;
                l.insert(start, val);
            }
        }
        vector<int> res(l.begin(), l.end());
        return res;
    }
};