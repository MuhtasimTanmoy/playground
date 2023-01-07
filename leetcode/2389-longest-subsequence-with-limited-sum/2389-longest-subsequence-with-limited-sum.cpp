class Solution {
public:
    vector<int> answerQueries(vector<int>& nums,
                              vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        
        vector<int> answer;
        for (auto query: queries) {
            int index = upper_bound(nums.begin(), nums.end(), query) - nums.begin();
            answer.push_back(index);
        }
        
        return answer;
    }
};