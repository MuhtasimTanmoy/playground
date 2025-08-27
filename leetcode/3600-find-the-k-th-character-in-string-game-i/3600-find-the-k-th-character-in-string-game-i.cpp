class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while (res.size() < k) {
            auto now = res;
            for (auto& c: now) if (c == 'z') c = 'a'; else c++;
            res += now;
        }
        cout<<res<<endl;
        return res[k-1];
    }
};