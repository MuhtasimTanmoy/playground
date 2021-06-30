class Solution {
public:
    bool isHappy(int n) {
        
        
        // 1111 -> [1, 1, 1, 1]
        // function<int(vector<int>)
        
        auto getDigits = [](int number) -> vector<int> {
            vector<int> digits;
            while( number != 0 ) {
                digits.push_back( number % 10 );
                number = number / 10;
            }
            return digits;
        };
        
        unsigned int currentValue = n;
        unsigned int prevValue = INT_MIN;
        unordered_set<unsigned int> previouslySeen;

        while(prevValue != currentValue) {
            
            prevValue = currentValue;
            vector<int> digits = getDigits(currentValue);
            
            unsigned int sum = 0;
               
            for(int i: digits) {
                sum += i*i;
            }
            currentValue = sum;
            if (previouslySeen.count(sum) == 1) {
                break;
            }
            previouslySeen.insert(sum);
        }
        
        return currentValue == 1 ? true : false;
    }
};