class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        auto get_num_with_base = [](int n, int b) {
            string res = "";
            while (n)
                res += to_string(n % b),
                n /= b;
            reverse(res.begin(), res.end());
            return res;
        };
        
        auto is_palin_for_base = [&](int n, int b) {
            auto num = get_num_with_base(n, b);
            cout<<num<<endl;
            int l = 0, r = num.size() - 1;
            while (l < r)
                if (num[l++] != num[r--])
                    return false;
            return true;
        };
                
        for (auto i = 2; i <= n - 2; i++) 
            if (!is_palin_for_base(n, i))
                return false;
        return true;
    }
};