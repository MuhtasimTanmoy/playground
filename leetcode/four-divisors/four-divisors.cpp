class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        auto getDivisorCount = [](int a) -> pair<int, int> {
            int sum = 1 + a;
            int count = 2;
            int i = 0;
            for(i = 2; i * i <= a; i++) {
                if (a % i == 0) {
                    count += 2;
                    sum += i;
                    sum += a / i;
                }
                
                if (i * i == a) {
                    count--;
                    sum -= i;
                }
            }
            return make_pair(count, sum);
        };
        
        int sum = 0;
        for(auto num: nums) {
            auto meta = getDivisorCount(num);
            if (meta.first == 4) sum += meta.second;
        }
        
        return sum;
    }
};