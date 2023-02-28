// Failed attempt
// Tried converging all input to avg to minimize distance
// But fails int this case 
// [4,1,5,20,3]
// avg = 6.6
// [ 4 2 5 5 6 ]

// class Solution {
// public:
//     int minimumDeviation(vector<int>& nums) {
//         double avg = 0;
//         for (int i = 0; i < nums.size(); i++) avg = (avg * i + nums[i]) / (i + 1);
//
//         for (auto &num: nums)
//                 while (true) {
//                     double toBe = (num & 1) ? num * 2: num / 2;
//                     if ( abs(toBe - avg) < abs(num - avg)) num = toBe; else break;
//                 }
//
//         int minNum = INT_MAX, maxNum = INT_MIN;
//         for (auto num: nums) 
//             minNum = min(minNum, num), maxNum = max(maxNum, num);
//
//         return (maxNum - minNum);
//     }
// };


// Fails for
// [2,10,8]
// As this is biased
// cannot use biased
// class Solution {
// public:
//     int minimumDeviation(vector<int>& nums) {
//         double avg = 0;
//         for (int i = 0; i < nums.size(); i++) avg = (avg * i + nums[i]) / (i + 1);
        
//         multiset<int> ordered_bag;
//         for (auto num: nums) ordered_bag.insert(num);
//         cout<< *ordered_bag.begin() <<" "<< *ordered_bag.rbegin() <<endl;
        
//         bool operationDone = true;
//         while (operationDone) {
//             auto first = *ordered_bag.begin(), last = *ordered_bag.rbegin();
//             for (auto num: {first, last}) {
//                 double toBe = (num & 1) ? num * 2: num / 2;
//                 if ( abs(toBe - avg) < abs(num - avg)) {
//                     ordered_bag.erase(num);
//                     ordered_bag.insert(toBe);
//                 } else operationDone = false;
//             }
//         }
//         return *ordered_bag.rbegin() - *ordered_bag.begin();
//     }
// };



class Solution {
public:
    int minimumDeviation(vector<int>& A) {
        set<int> s;
        for (int &a : A) s.insert(a % 2 ? a * 2 : a);
        int res = *s.rbegin() - *s.begin();
        while (*s.rbegin() % 2 == 0) {
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            res = min(res, *s.rbegin() - *s.begin());
        }
        return res;
    }
};