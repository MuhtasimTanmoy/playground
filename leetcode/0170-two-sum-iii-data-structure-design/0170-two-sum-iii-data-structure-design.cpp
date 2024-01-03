// class TwoSum {
//     unordered_map<long, long> bag;
// public:
//     TwoSum() {}
    
//     void add(int number) {
//         bag[number]++;
//     }
    
//     bool find(int value) {
//         for (auto [key, val]: bag)
//             if (bag.count(value - key)) {
//                 if (key != (value - key)) return true;
//                 return val > 1;
//             }
//         return false;
//     }
// };


class TwoSum {
  unordered_map<long, long> ctr;
public:
  void add(int number) {
    ctr[number]++;
  }

  bool find(int value) {
    for (auto nc : ctr)
      if (ctr.count(value - nc.first) && (nc.first != value - nc.first || nc.second > 1))
        return true;
    return false;
  }
};