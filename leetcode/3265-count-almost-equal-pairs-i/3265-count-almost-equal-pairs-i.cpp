class Solution {
private:
    bool almostEqual(int x, int y){
        string l = to_string(x), r = to_string(y);
        while (l.size() < r.size()) l = '0' + l; 
        while (l.size() > r.size()) r = '0' + r;
                
        int diff = 0;
        vector<int> count(10, 0);
        for(int i = 0; i < l.size(); i++) 
            diff += l[i] != r[i], count[l[i] - '0']++, count[r[i] - '0']--;
        for (auto i: count) if (i) return false;
        return diff <= 2;
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                count += almostEqual(nums[i], nums[j]);
        return count;
    }
};