class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;
        sort(freq.begin(), freq.end());
        
        int f_max = freq.back();
        int idle_time = (freq.back() - 1) * n;
        for (int i = freq.size() - 2; i >= 0 && idle_time > 0; --i) 
            idle_time -= min(f_max - 1, freq[i]);
        idle_time = max(0, idle_time);
        return idle_time + tasks.size();
    }
};