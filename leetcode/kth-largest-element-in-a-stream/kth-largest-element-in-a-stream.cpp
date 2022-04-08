class KthLargest {
public:
    vector<int> v;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        v = nums;
        this->k = k;
        sort(v.begin(), v.end());
    }
    
    int add(int val) {
        auto it = lower_bound(v.begin(), v.end(), val);
        v.insert(it, val);
        
        return v[v.size()-k];
    }
};

// or multiset
// class KthLargest {
// public:
    
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int K;
    
//     KthLargest(int k, vector<int>& nums) {
//         K = k;
//         for(int x : nums) {
//             pq.push(x);
//             if(pq.size() > k) {
//                 pq.pop();
//             }
//         }
//     }
    
//     int add(int val) {
//         pq.push(val);
//         if(pq.size() > K) {
//             pq.pop();
//         }
//         return pq.top();
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */