class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
    //create a vector and a map
    vector<int> v;
    unordered_map<int, int> m;
    //store the nums in map 
    for(auto num: nums){
        m[num]++;
    }
    //create priority_queue and store the value
    priority_queue<pair<int,int>> q;
    for(auto val: m){
        q.push({val.second, val.first});
    }
    //push the tow k value in vector
    while(k--){
        v.push_back(q.top().second);
        q.pop();
    }
    // return vector
    return v;
}
};