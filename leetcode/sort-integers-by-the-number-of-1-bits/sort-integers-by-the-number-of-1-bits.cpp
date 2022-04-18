class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto count1 = [](int i)->int {
            int count = 0;
            while(i) {
                if(i & 1)count++;
                i=i>>1;
            }
            return count;
        };
        
        sort(begin(arr), end(arr), [&count1](int &left, int &right) {
            int left1 = count1(left);
            int right1 = count1(right);
            if (left1 == right1) { return left < right; }
            else return left1 < right1;
        });
        
        return arr;
    }
};