class Logger {
    unordered_map<string, int> bag;
public:
    Logger() { }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (bag.count(message)) {
            auto prevTime = bag[message];
            if (timestamp - prevTime >= 10) {
                bag[message] = timestamp;
                return true;
            } else return false;
        } else {
            bag[message] = timestamp;
            return true;
        }
    }
};