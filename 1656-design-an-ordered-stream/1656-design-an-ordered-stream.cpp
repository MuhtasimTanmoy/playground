class OrderedStream {
public:
    OrderedStream(int n) {
        li = vector<string>(n + 1, "");
    }
    
    vector<string> insert(int idKey, string value) {
        li[idKey] = value;
        if (left != idKey) return {};
        
        vector<string> res {li[left]};
        left++;
        while (left < li.size() && li[left].size()) {
            res.push_back(li[left]);
            left++;
        }
        return res;
    }
private:
    vector<string> li;
    int left = 1;
};
