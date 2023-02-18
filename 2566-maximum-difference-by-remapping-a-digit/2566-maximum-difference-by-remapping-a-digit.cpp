class Solution {
public:
    int minMaxDifference(int num) {
        auto ns = to_string(num), maxNum = ns, minNum = ns;
        auto first = ns[0];
        for (auto &c: minNum) if (c == first) c = '0';
        
        int index = 0;
        while (index < ns.size() && ns[index] == '9') { index++; };
        if (index == ns.size()) return num - stoi(minNum);
            
        first = ns[index];
        for (auto &c: maxNum) if (c == first) c = '9';
        return stoi(maxNum) - stoi(minNum);
    }
};