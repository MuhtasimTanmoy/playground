class Solution {
public:
    unordered_map<int,vector<char>> digit_letters;
    vector<int> nums;
    vector<string> words;
    
    void findCombinations(int position, string current_word) {
        vector<char> letters = digit_letters[nums[position]];
        for (auto l:letters) {
            if (position == nums.size() - 1) {
                words.push_back(current_word + l);
            }
            else {
                findCombinations(position + 1, current_word + l);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        
        digit_letters[2] = {'a','b','c'};
        digit_letters[3] = {'d','e','f'};
        digit_letters[4] = {'g','h','i'};
        digit_letters[5] = {'j','k','l'};
        digit_letters[6] = {'m','n','o'};
        digit_letters[7] = {'p','q','r','s'};
        digit_letters[8] = {'t','u','v'};
        digit_letters[9] = {'w','x','y','z'};
        
        for (auto d:digits) {
            nums.push_back(d - '0');
        }
        
        findCombinations(0, "");
        
        return words;
    }
};