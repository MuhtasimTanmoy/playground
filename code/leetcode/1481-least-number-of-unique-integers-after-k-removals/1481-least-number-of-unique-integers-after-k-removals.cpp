class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int prev = 0, count = 1;
        for (int i = 1; i < arr.size(); i++)
            if (arr[i-1] == arr[i]) count++;
            else {  
                pq.push(count);
                count = 1;
            }
        pq.push(count);
        while (!pq.empty() && k > 0) {
            auto top = pq.top(); pq.pop();
            k -= top;
            if (k <= 0) {
                if (k < 0) pq.push(abs(k));
                break;
            }
        }
        return pq.size();
    }
};