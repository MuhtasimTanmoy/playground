class Solution {
public:
    int minimumSum(int num) {
        vector<int> numbers;
        while(num) {
            numbers.push_back(num%10);
            num/=10;
        }
        sort(begin(numbers), end(numbers));
        return numbers[0] * 10 + numbers[2] + numbers[1] * 10 + numbers[3];
    }
};