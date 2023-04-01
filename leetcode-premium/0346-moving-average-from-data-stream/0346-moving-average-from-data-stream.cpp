class MovingAverage {
    int size;
    double sum;
    deque<int> dq;
public:
    MovingAverage(int size): size(size) {
        sum = 0;
    }
    
    double next(int val) {
        dq.push_back(val);
        sum += val;
        if (dq.size() > size) sum -= dq.front(), dq.pop_front();
        return sum / dq.size();
    }
};