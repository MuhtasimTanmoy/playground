class OrderedStream {
    vector<string> arr;
    int ptr;
public:
    OrderedStream(int n) {
        arr.resize(n, "");
        ptr = 0;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> res;
        arr[id-1] = value;
        while (ptr < arr.size() && arr[ptr] != "") 
            res.push_back(arr[ptr++]);
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */