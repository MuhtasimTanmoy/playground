class RangeFreqQuery {
    vector<int> m[10000];
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) 
            m[arr[i] - 1].push_back(i);
    }
    int query(int left, int right, int value) {
        const auto& arr = m[value - 1];    
        auto a = lower_bound(arr.begin(), arr.end(), left);
        auto b = upper_bound(a, arr.end(), right); 
        return distance(a, b);
    }
};