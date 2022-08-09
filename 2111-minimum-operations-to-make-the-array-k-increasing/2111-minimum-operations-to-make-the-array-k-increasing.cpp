class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int longest = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> mono;
            for (int j = i; j < arr.size(); j += k)
                if (mono.empty() || mono.back() <= arr[j]) mono.push_back(arr[j]);
                else *upper_bound(begin(mono), end(mono), arr[j]) = arr[j];
            longest += mono.size();
        }
        return arr.size() - longest;
    }
};