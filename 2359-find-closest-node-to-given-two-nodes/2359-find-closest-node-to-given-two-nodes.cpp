

class Solution {
public:
    int closestMeetingNode(vector<int>& e, int n1, int n2, 
                           int res = -1, int min_dist = INT_MAX) {
        vector<int> m1(e.size(), -1), m2(e.size(), -1);
        for (int i = n1, dist = 0; i != -1 && m1[i] == -1; i = e[i]) m1[i] = dist++;
        for (int i = n2, dist = 0; i != -1 && m2[i] == -1; i = e[i]) m2[i] = dist++;
        for (int i = 0; i < e.size(); i++)
           if (min(m1[i], m2[i]) >= 0 && max(m1[i], m2[i]) < min_dist) 
                res = i, min_dist = max(m1[i], m2[i]);
        return res;
    }
}; 


    