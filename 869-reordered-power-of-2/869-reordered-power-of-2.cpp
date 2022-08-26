// class Solution {
// public:
//     bool reorderedPowerOf2(int n) {
        
//         auto mapper = [](int num) {
//             vector<int> li(26, 0);
//             while(num) {
//                 int index = num % 2;
//                 li[index]++;
//                 num /= 2;
//             }
//             return li;
//         };
        
//         auto mappingOfN = mapper(n);
//         for (int i = 0; i < 31; i++) {
//             auto curr =  mapper(1 << i);
//             if (mappingOfN == curr) return true;
//         }
//         return false;
//     }
// };


class Solution {
public:
    vector<int> Helper(long n) {
        vector<int> num(10);
        while (n) {
            num[n % 10]++;
            n = n / 10;
        }
        return num;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int>v = Helper(n);
        for (int i = 0; i < 31; i++)
            if ( v == Helper( 1 << i) )
                return true;
        return false;
    }
};