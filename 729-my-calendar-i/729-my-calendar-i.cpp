class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto &date: calendar) {
            if (max(date.first, start) < min(date.second, end)) {
                return false;
            }
        }
        calendar.push_back({start, end});
        return true;
    }
    vector<pair<int,int>> calendar;
};
