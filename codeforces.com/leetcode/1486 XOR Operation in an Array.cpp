class Solution {
public:
    int xorOperation(int n, int start) {
        int _xor = 0;
        for(int j= 0; j<n; j++){
            _xor = (j*2 + start) ^ _xor;
        }
        return _xor;
    }
};