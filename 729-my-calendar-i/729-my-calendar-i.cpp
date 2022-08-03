class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);
        if (it == mp.end() || it->second >= end) {
            mp[end] = start;
            return true;
        } else return false;
    }
};