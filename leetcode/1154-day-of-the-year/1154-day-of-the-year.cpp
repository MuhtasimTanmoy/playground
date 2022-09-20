class Solution {
    bool isLeap(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); 
    }
public:
    int dayOfYear(string date) {
        int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)), day = stoi(date.substr(8));
        return days[month - 1] + day + (month > 2 && (isLeap(year) ? 1: 0));        
    }
};