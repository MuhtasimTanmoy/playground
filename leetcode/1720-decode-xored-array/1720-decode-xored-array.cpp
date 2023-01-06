class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size() + 1); res[0] = first;
        for (int i = 0; i < encoded.size(); i++) res[i + 1] = encoded[i] ^ res[i]; 
        return res;
    }
};