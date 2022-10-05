class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> mapping(size(fruits), 0);
        int type = 0;
        
        int left = 0;
        int right = 0;
        
        int result = 0;
        
        for(auto fruit: fruits) {
            if (++mapping[fruit] == 1) type++;
            while (type > 2) if (--mapping[fruits[left++]] == 0) type--;
            
            right++;
            result = max(result, right - left);
        }
        
        return result;
    }
};