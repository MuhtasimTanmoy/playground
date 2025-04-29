class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::unordered_set<int> uniqueNumbers;
        int n = digits.size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                for (int k = 0; k < n; k++)
                    if (i != j && i != k && j != k) 
                        if (digits[i]) 
                            if (digits[k] % 2 == 0) { 
                                int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                                uniqueNumbers.insert(number);
                            }
        return uniqueNumbers.size();
    }
};