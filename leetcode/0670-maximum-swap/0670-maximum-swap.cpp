class Solution {
public:
    int maximumSwap(int num) {
        auto n_str = to_string(num);
        int n = n_str.size();
        
        vector<int> right(n, 0);
        right[n - 1] = n - 1;
        
        for (int i = n_str.size() - 2; i >= 0; i--) 
            right[i] = n_str[right[i + 1]] >= n_str[i] ? right[i + 1]: i;
        
        // for (auto val: right) cout<<val<<endl;
        
        for (int i = 0; i < n_str.size(); i++) 
            if (n_str[i] < n_str[right[i]]) {
                swap(n_str[i], n_str[right[i]]);
                break;
            }
        
        return stoi(n_str);
    }
};