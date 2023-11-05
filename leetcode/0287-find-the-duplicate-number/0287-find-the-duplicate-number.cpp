
/*
1.

unordered_map
insert, check

extra memory => O(n)
*/


/*
2.

sort
check

extra compute => nlogn
*/



/*
3.

sort
check

extra compute => nlogn
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            auto a = abs(nums[i]);
            if (nums[a - 1] < 0) return a;
            nums[a - 1] = -nums[a - 1];
        }
        return 0;
    }
};