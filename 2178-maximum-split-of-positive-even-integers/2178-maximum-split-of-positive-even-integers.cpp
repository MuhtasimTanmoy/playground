
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) return {};
        vector<long long>  ans;
        function<bool(long, long)> go = [&] (auto val, auto sum) {
            if (sum == 0) return true;
            if (sum < val) return false;
            ans.push_back(val);
            if (go(val + 2, sum - val)) return true;
            ans.pop_back();
            return go(val + 2, sum);
        };
        go(2, finalSum);
        return ans;
    }
};

// class Solution {
// public:
//     vector<long long> maximumEvenSplit(long long finalSum) {
//         if (finalSum & 1) return [}]
//     }
// };