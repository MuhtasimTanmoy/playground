class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        auto isSelfDeviding = [](int num) -> bool {
            int cache = num;
            while(cache) {
                int rem = cache % 10;
                if (!rem || (num % rem != 0)) return false;
                cache /= 10;
            }
            return true;
        };
        
        vector<int> selfDividingNumbers;
        for(int i = left; i <= right; i++)
            if (isSelfDeviding(i)) selfDividingNumbers.push_back(i);
        return selfDividingNumbers;
    }
};