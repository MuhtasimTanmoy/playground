class Solution {
public:
    int sumofDigit(int n) {
        int sum=0;
        while (n) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    
    int countBalls(int a, int b) {
        unordered_map<int,int> mp;
        int maxi = 0;
        for (int i = a; i <= b; i++ ) {
            int sum = sumofDigit(i);
            mp[sum]++;
            maxi = max(mp[sum],maxi);
        }
        return maxi;
    }
};