// Gets TLE
// class ProductOfNumbers {
//     vector<int> li;
// public:
//     ProductOfNumbers() { }
    
//     void add(int num) {
//         li.push_back(num);
//     }
    
//     int getProduct(int k) {
//         int product = 1;
//         int index = li.size() - 1;
//         while(k--) product *= li[index--];
//         return product;
//     }
// };

class ProductOfNumbers {
    vector<long long> pr = { 1 };
public:
    ProductOfNumbers() { }
    
    void add(int num) {
        if (num == 0) pr = { 1 };
        else pr.push_back(pr.back() * num);
    }
    
    int getProduct(int k) {
        if (k >= pr.size()) return 0;
        return pr.back() / pr[pr.size() - k - 1];
    }
};

