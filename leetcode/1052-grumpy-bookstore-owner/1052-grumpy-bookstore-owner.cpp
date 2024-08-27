class Solution {
public:
    int maxSatisfied(vector<int>& CS, vector<int>& grumpy, int minutes) {
        int happy = 0;
        for (auto i = 0; i < CS.size(); i++)
            if (!grumpy[i])
                happy += CS[i];
        int max_extra_happy = 0, extra_happy = 0;
        for (auto i = 0; i < CS.size(); i++) {
            if (grumpy[i]) extra_happy += CS[i];
            if (i >= minutes && grumpy[i - minutes]) extra_happy -= CS[i - minutes];
            max_extra_happy = max(max_extra_happy, extra_happy);
        }
        return happy + max_extra_happy;
    }
};